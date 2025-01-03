#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> leer_reglas(ifstream &file) {
    unordered_map<int, vector<int>> precedencia;
    string line;
    while (getline(file, line) && !line.empty()) {
        int x, y;
        char delimiter;
        stringstream ss(line);
        ss >> x >> delimiter >> y;
        precedencia[x].push_back(y);
    }
    return precedencia;
}

vector<vector<int>> leer_actualizaciones(ifstream &file) {
    vector<vector<int>> actualizaciones;
    string line;
    while (getline(file, line)) {
        vector<int> update;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            update.push_back(num);
            if (ss.peek() == ',') ss.ignore();
        }
        actualizaciones.push_back(update);
    }
    return actualizaciones;
}

bool es_orden_correcto(const vector<int> &update, const unordered_map<int, vector<int>> &precedencia) {
    unordered_set<int> seen;
    for (size_t i = 0; i < update.size(); ++i) {
        seen.insert(update[i]);
        if (precedencia.find(update[i]) != precedencia.end()) {
            for (int siguiente : precedencia.at(update[i])) {
                if (seen.find(siguiente) != seen.end()) {
                    return false;
                }
            }
        }
    }
    return true;
}

int suma_numeros_centrales(const vector<vector<int>> &actualizaciones, const unordered_map<int, vector<int>> &precedencia) {
    int suma = 0;
    for (const auto &update : actualizaciones) {
        if (es_orden_correcto(update, precedencia)) {
            suma += update[update.size() / 2];
        }
    }
    return suma;
}

int main() {
    string filename = "Puzzle5";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return 1;
    }

    auto precedencia = leer_reglas(file);
    auto actualizaciones = leer_actualizaciones(file);
    
    int resultado = suma_numeros_centrales(actualizaciones, precedencia);
    cout << "La suma de los números de página centrales de las actualizaciones correctamente ordenadas es: " << resultado << endl;

    return 0;
}

