// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"
char parse(char* symbol) {
    if ((*symbol >= 'A' && *symbol <= 'Z') || (*symbol >= 'a' && *symbol <= 'z')) {
        if (*symbol >= 'A' && *symbol <= 'Z') {
            *symbol = *symbol + ('a' - 'A');
        }
        return *symbol;
    }
    return *symbol;
}

BST<std::string> makeTree(const char* filename) {
    BST<std::string> BSTtree;
    std::ifstream file(filename);
    std::string result;
    while (!file.eof()) {
        char symbol = file.get();
        symbol = parse(&symbol);
        if (symbol >= 'a' && symbol <= 'z')
            result += symbol;
        else {
            BSTtree.add(result);
            result.clear();
        }
    }
    return BSTtree;
}
