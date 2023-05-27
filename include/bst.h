// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include<algorithm>
template <typename T>
class BST {
 private:
    struct NODE {
        T value;
        int count;
        NODE *left, *right;
    };
    NODE* root;
    NODE* addNODE(NODE*, const T& value) {
        if (root == nullptr) {
            root = new NODE;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNODE(root->left, value);
        } else if (root->value < value) {
            root->right = addNODE(root->right, value);
        } else
            root->count += 1;
        return root;
    }
    int heightTree(NODE* root) {
        return std::max(heightTree(root->left), heightTree(root->left)) + 1;
    }
    NODE* searchTree(NODE* root, const T& value) {
        if (root == nullptr || root->value == value) return root;
        if (value > root->value)
            return searchTree(root->right, value);
        else
            return searchTree(root->left, value);
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& value) {
        root = addNODE(root, value);
    }
    int depth() { return heightTree(root) - 1; }
    int search(const T& value) {
        NODE* current = serachTree(root, value);
        if (current == nullptr) return 0;
        else return current->count;
    }
};
#endif  // INCLUDE_BST_H_
