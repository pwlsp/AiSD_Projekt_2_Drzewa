#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

#include "../include/struct_tree.h"

void pre_order(tree *&root){
    std::cout << root->value << " ";
    if(root->left != NULL) pre_order(root->left);
    if(root->right != NULL) pre_order(root->right);
}

void in_order(tree *&root){
    if(root->left != NULL) in_order(root->left);
    std::cout << root->value << " ";
    if(root->right != NULL) in_order(root->right);
}

void post_order(tree *&root){
    if(root->left != NULL) post_order(root->left);
    if(root->right != NULL) post_order(root->right);
    std::cout << root->value << " ";
}

void print_tree(tree *&root, std::string method, std::string tree_type){ 
    std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
    if(root){
        if(method == "all"){
            std::cout << "Pre-order: ";
            pre_order(root);
            std::cout << "\nIn-order: ";
            start = std::chrono::high_resolution_clock::now();
            in_order(root);
            stop = std::chrono::high_resolution_clock::now();
            std::cout << "\nPost-order: ";
            post_order(root);
            std::cout << "\n";
        }
        else if(method == "pre"){
            std::cout << "Pre-order: ";
            pre_order(root);
            std::cout << "\n";
        }
        else if(method == "in"){
            std::cout << "In-order: ";
            in_order(root);
            std::cout << "\n";
        }
        else if(method == "post"){
            std::cout << "Post-order: ";
            post_order(root);
            std::cout << "\n";
        }
        std::cout << "The tree has been printed successfully.\n";
    }
    else{
        std::cout << "The tree does not exist.\n";
    }
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::string file_name = "../results/" + tree_type + "_print_in_order.txt";
    std::fstream file;
    file.open(file_name, std::ios::app); //dopisywanie
    file << duration.count() << "\n";
    file.close();
}