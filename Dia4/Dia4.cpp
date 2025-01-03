#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Dirección de exploración: [vertical, horizontal, diagonal]
int dirs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && y >= 0 && x < rows && y < cols;
}

int countXMAS(const vector<string>& board, int rows, int cols) {
    int count = 0;
    string target = "XMAS";

    // Iterar por cada celda en el tablero
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Si encontramos una 'X', intentamos encontrar la palabra "XMAS" en las 8 direcciones
            if (board[i][j] == 'X') {
                // Probar todas las direcciones
                for (int d = 0; d < 8; ++d) {
                    int nx = i, ny = j;
                    bool match = true;

                    // Verificar si las siguientes letras forman "XMAS"
                    for (int k = 0; k < target.length(); ++k) {
                        if (!isValid(nx, ny, rows, cols) || board[nx][ny] != target[k]) {
                            match = false;
                            break;
                        }
                        // Mover en la dirección
                        nx += dirs[d][0];
                        ny += dirs[d][1];
                    }

                    if (match) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    string filename = "PuzzleInput";  // Nombre del archivo de entrada
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    vector<string> board;
    string line;

    // Leer las líneas del archivo y almacenarlas en el vector board
    while (getline(inputFile, line)) {
        board.push_back(line);
    }

    inputFile.close();

    int rows = board.size();
    int cols = board.empty() ? 0 : board[0].size();

    // Contar las ocurrencias de "XMAS"
    int result = countXMAS(board, rows, cols);

    // Mostrar el resultado
    cout << "La palabra 'XMAS' aparece " << result << " veces." << endl;

    return 0;
}

