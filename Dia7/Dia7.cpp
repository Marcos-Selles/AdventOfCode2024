#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int applyOperation(int left, int right, char op) {
    return (op == '+') ? left + right : left * right;
}

bool evaluateExpression(const std::vector<int>& numbers, const std::vector<char>& operations, int target) {
    int result = numbers[0];
    for (size_t i = 0; i < operations.size(); ++i) {
        result = applyOperation(result, numbers[i + 1], operations[i]);
    }
    return result == target;
}

bool checkEquation(const std::vector<int>& numbers, int target) {
    size_t n = numbers.size();
    if (n == 1) {
        return numbers[0] == target;  // Caso base, solo un número
    }

    // Comprobamos todas las combinaciones posibles de operadores
    size_t numOps = n - 1;
    std::vector<char> ops(numOps);
    std::vector<char> possibleOps = {'+', '*'};

    // Generamos todas las combinaciones posibles de los operadores
    for (size_t i = 0; i < (1 << numOps); ++i) {
        for (size_t j = 0; j < numOps; ++j) {
            ops[j] = possibleOps[(i >> j) & 1];  // Asignamos '+' o '*' dependiendo de la máscara
        }

        // Evaluamos la expresión con esta combinación de operadores
        if (evaluateExpression(numbers, ops, target)) {
            return true;
        }
    }

    return false;
}

bool readFile(const std::string& fileName, std::vector<std::string>& lines) {
    std::ifstream in(fileName);
    if (!in) {
        std::cerr << "Cannot open file " << fileName << '\n';
        return false;
    }

    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> lines;
    if (!readFile(argv[1], lines)) {
        return EXIT_FAILURE;
    }

    int totalSum = 0;

    for (const auto& line : lines) {
        std::istringstream iss(line);
        int result;
        iss >> result;  // Leer el valor de prueba
        iss.ignore(1);  // Ignorar el ':'
        
        std::vector<int> ops;
        int num;
        while (iss >> num) {
            ops.push_back(num);
        }

        // Verificar si la combinación de operadores puede producir el valor de prueba
        if (checkEquation(ops, result)) {
            totalSum += result;
        }
    }

    std::cout << "Total calibration sum: " << totalSum << '\n';

    return EXIT_SUCCESS;
}

