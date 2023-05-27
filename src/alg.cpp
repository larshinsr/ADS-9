// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <cctype>
#include "bst.h"
BST<std::string> makeTree(const char* filename) {
    BST<std::string> BSTtree;
    std::ifstream file(filename);
    std::string result;
    while (!file.eof()) {
        char symbol = tolower(file.get());
        if (isalpha(symbol)) {
            result += symbol;
        } else {
            BSTtree.add(result);
            result = "";
        }
    }
    return BSTtree;
}
