// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
    BST<std::string> BSTtree;
    std::ifstream file(filename);
    std::string result;
    while (!file.eof()) {
        char symbol = file.get();
        if (symbol >= 'a' && symbol <= 'z') {
           result+=symbol;
        }
        if (symbol >= 'A'&&symbol <= 'Z') {
            symbol = symbol+('a'-'A');
            BSTtree.add(result);
            result+=symbol;
        }
    }
    return BSTtree;
}
