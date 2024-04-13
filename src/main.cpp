#include <iostream>
#include <vector>
#include <string>

#include "../include/avl.h"
#include "../include/bst.h"
#include "../include/actions.h"

int main(int argc, char *argv[]){
    tree * root;
    int nodes, p;
    std::string pom;
    std::vector <int> data;
    //dodawanie elementu
    // tree * node;
    // node = new tree;
    // node->left = NULL;
    // node->value = 2137;
    // root->right = node;
    // node->prev=root;

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
    for(int i = 0; i < nodes; i++) {std::cin >> p; data.push_back(p);}
    for(int i = 0; i < nodes; i++) std::cout << data[i] << " ";
    std::cin.sync();
            
            
    //         int j = 0;
    //         pom = "";
    //         while(data[j] != ' '){
    //             pom += data[j];
    //             j++;
    //         }
    //         nodes = std::stoi(pom);
    //         pom = "";
    //     for(int i = 0; i < nodes; i++){
    //         while(data[j] != ' '){
    //             pom += data[j];
    //             j++;
    //         }
    //         data.push_back(std::stoi(pom));
    //     }
    // }
    // else if(std::string(argv[3] == "<<"))

    

    if(tree_type == "AVL") avl(root, data);
    if(tree_type == "BST") bst(root, data);

    std::cout << actions(root);

    return 0;  
}