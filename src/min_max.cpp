#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "../include/struct_tree.h"

int min_element(tree *root){
    int mini;
    tree *L = root;
    if(root->left == NULL) return L->value;
    while(L->left != NULL){
        L = L->left;
    }
    mini = L->value;
    return mini;
}

int max_element(tree *root){
    int maxi;
    tree *R = root;
    if(root->right == NULL) return R->value;
    while(R->right != NULL){
        R = R->right;
    }
    maxi = R->value;
    return maxi;
}

std::string min_max(tree *root){
    std::cout << "Min: " << min_element(rooti) << "\n";
    std::cout << "Max: " << max_element(rooti) << "\n";
    std::stringstream resultStream;
    resultStream << "Min and max elements have been found\n";
    return resultStream.str();
}