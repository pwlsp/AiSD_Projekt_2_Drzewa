#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <ios>
#include <limits>
#include <chrono>
#include <fstream>

#include "../include/avl.h"
#include "../include/bst.h"
#include "../include/actions.h"

int main(int argc, char *argv[]){

    tree * root;
    root = new tree;
    int nodes, p; std::string pom;
    std::vector <int> data;

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
    std::cout << "\nnodes> " << nodes << "\n";
    for(int i = 0; i < nodes; i++) {std::cin >> p; data.push_back(p);} //przy herestring dac w " "
    std::cout << "insert> ";
    for(int i = 0; i < nodes; i++) std::cout << data[i] << " ";
    std::cout << "\n";

    std::string file_name = "../results/" + tree_type + "_time.txt";
    std::fstream file;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
    file.open(file_name, std::ios::out | std::ios::app);
    if(tree_type == "AVL"){
        start = std::chrono::high_resolution_clock::now();
        avl(root, data);
        stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        file << nodes << " " << duration.count() << "\n";
    }
    if(tree_type == "BST"){
        start = std::chrono::high_resolution_clock::now();
        bst(root, data);
        stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        file << nodes << " " << duration.count() << "\n";
    }
    file.close();

    actions(root, nodes, tree_type);

    delete root;
    return 0;
}