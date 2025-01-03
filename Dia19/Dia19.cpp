#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// Definición del nodo del árbol binario
struct TreeNode {
    std::string word;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& w) : word(w), left(nullptr), right(nullptr) {}
};

// Insertar una palabra en el árbol binario
TreeNode* insert(TreeNode* root, const std::string& word) {
    if (root == nullptr) {
        return new TreeNode(word);
    }
    if (word < root->word) {
        root->left = insert(root->left, word);
    } else if (word > root->word) {
        root->right = insert(root->right, word);
    }
    return root;
}

// Buscar una palabra en el árbol binario
bool search(TreeNode* root, const std::string& word) {
    if (root == nullptr) {
        return false;
    }
    if (root->word == word) {
        return true;
    }
    if (word < root->word) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

bool readFile(const std::string& fileName, std::vector<std::string>& lines)
{
    std::ifstream in{fileName};
    if (!in) {
        std::cerr << "Cannot open file " << fileName << '\n';
        return false;
    }
    std::string str;
    while (std::getline(in, str)) {
        lines.push_back(str);
    }
    return true;
}

bool canBuild(TreeNode* root, const std::string& word, std::map<std::string, bool>& cache)
{
    if (auto it = cache.find(word); it != cache.end()) {
        return it->second;
    }
    if (search(root, word)) {
        cache[word] = true;
        return true;
    }
    bool res = false;
    for (size_t i = 1; i < word.size(); ++i) {
        const auto left = word.substr(0, i);
        if (!canBuild(root, left, cache)) {
            continue;
        }
        const auto right = word.substr(i, word.size() - i);
        if (canBuild(root, right, cache)) {
            res = true;
            break;
        }
    }
    cache[word] = res;
    return res;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        return EXIT_FAILURE;
    }
    std::vector<std::string> lines{};
    if (!readFile(argv[1], lines)) {
        return EXIT_FAILURE;
    }

    TreeNode* root = nullptr;
    {
        std::istringstream iss{lines[0]};
        std::string p;
        while (iss >> p) {
            if (p[p.size() - 1] == ',') {
                p = p.substr(0, p.size() - 1);
            }
            if (p.empty()) {
                continue;
            }
            root = insert(root, p);
        }
    }

    std::vector<size_t> goods;

    {  // Parte 1
        int count = 0;
        std::map<std::string, bool> cache;
        for (size_t i = 2; i < lines.size(); ++i) {
            if (canBuild(root, lines[i], cache)) {
                goods.push_back(i);
                ++count;
            }
        }
        std::cout << count << '\n';
    }

    return EXIT_SUCCESS;
}

