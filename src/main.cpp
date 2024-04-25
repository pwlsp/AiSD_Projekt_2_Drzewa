#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <ios>
#include <limits>
#include <sstream>

#include "../include/avl.h"
#include "../include/bst.h"
#include "../include/actions.h"

int main(int argc, char *argv[]){

    tree * root;
    root = new tree;
    int nodes, p; std::string pom;
    std::vector <int> data;
    //dodawanie elementu
    // tree * node;
    // node = new tree;
    // node->left = NULL;
    // node->value = 2137;
    // root->right = node;

    if(argc <= 2){
        std::cout << "No arguments given\n";
        return 1;
    }
    if(std::string(argv[1]) != "--tree"){
        std::cout << "Wrong arguments\n";
        return 1;
    }
    std::string tree_type = std::string(argv[2]);
    std::cin >> nodes;
    std::cout << "nodes> " << nodes << "\n";
    for(int i = 0; i < nodes; i++) {std::cin >> p; data.push_back(p);} //przy herestring dac w " "
    std::cout << "insert> ";
    for(int i = 0; i < nodes; i++) std::cout << data[i] << " ";
    std::cout << "\n";

    if(tree_type == "AVL") avl(root, data);
    if(tree_type == "BST") bst(root, data);
    
    actions(root, nodes);
    
    delete root;
    return 0;  
}