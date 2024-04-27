#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <fstream>

#include "../include/struct_tree.h"

int min_element(tree *&root){
    int mini;
    tree *L = root;
    if(L->left == NULL) return L->value;
    while(L->left != NULL){
        L = L->left;
    }
    mini = L->value;
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
    return maxi;
}

void min_max(tree *&root, std::string tree_type){
    std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Min: " << min_element(root) << "\n";
    std::cout << "Max: " << max_element(root) << "\n";
    stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::string file_name = "../results/" + tree_type + "_min_max.txt";
    std::fstream file;
    file.open(file_name, std::ios::app); //dopisywanie
    file << duration.count() << "\n";
    file.close();
}