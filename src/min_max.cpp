#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "../include/struct_tree.h"

int min_element(tree *&root){
    int mini;
    tree *L = root;
    if(L->left == NULL) return L->value;
    while(L->left != NULL){
        std::cout << L->value << " ";
        L = L->left;
    }
    mini = L->value;
    L = NULL; delete L;
    std::cout << "wynik ";
    return mini;
}

int max_element(tree *&root){
    int maxi;
    tree *R = root;
    if(R->right == NULL) return R->value;
    while(R->right != NULL){
        R = R->right;
    }
    maxi = R->value;
    R = NULL; delete R;
    return maxi;
}

void min_max(tree *&root){
    std::cout << "Min: " << min_element(root) << "\n";
    std::cout << "Max: " << max_element(root) << "\n";
}