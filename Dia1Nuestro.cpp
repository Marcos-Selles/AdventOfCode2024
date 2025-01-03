#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Function to read file
bool readFile(const string& fileName, vector<pair<int, int>>& pairs) {
    ifstream in{fileName};
    if (!in) {
        cerr << "Cannot open file " << fileName << '\n';
        return false;
    }
    string line;
    while (getline(in, line)) {
        istringstream iss{line};
        int i1{}, i2{};
        if (iss >> i1 >> i2) {
            pairs.emplace_back(i1, i2);
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return EXIT_FAILURE;
    }

    vector<pair<int, int>> pairs;
    if (!readFile(argv[1], pairs)) {
        return EXIT_FAILURE;
    }

    vector<int> c1; //vector Columna 1
    vector<int> c2; // Vector columna 2
    for (const auto& [l, r] : pairs) {
        c1.push_back(l);
        c2.push_back(r);
    }

    sort(c1.begin(), c1.end()); 
    sort(c2.begin(), c2.end());

    int DistanciaTotal = 0;
    for (size_t i = 0; i < c1.size(); ++i) {
        DistanciaTotal += abs(c1[i] - c2[i]);
    }
    cout << "Distancia Total: " << DistanciaTotal << '\n';

    return EXIT_SUCCESS;
}

