#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "../include/min_max.h"
#include "../include/print_tree.h"
#include "../include/remove_element.h"
#include "../include/delete_tree.h"
#include "../include/rebalance_tree.h"
#include "../include/struct_tree.h"

void actions(tree *&root, int nodes){
    std::cout << "\nActions\n";
    std::string message = "Help\t\tShow this message\nPrint\t\tPrint the tree using In-order, Pre-order, Post-order\nMinMax\t\tShow min and max element\nRemove\t\tRemove elements of the tree\nDelete\t\tDelete whole tree\nExport\t\tExport the tree to tickzpicture\nRebalance\tRebalance the tree\nExit\t\tExits the program (same as ctrl+D)\n";
    std::string action;
    while(std::cin){
        std::cin >> action;
        if(action != "") std::cout << "\naction> " << action << "\n";
        if(action == "Help"){
           std::cout << message;
        }
        else if(action == "Print"){
            print_tree(root,"all");
        }
        else if(action == "MinMax"){
            min_max(root);
        }
        else if(action == "Remove"){
            std::string line;
            int element;
            std::cin.ignore();
            std::getline(std::cin, line);
            std::stringstream elements(line);
            std::cout << "remove> ";
            while(elements >> element){
                std::cout << element << " ";
                remove_element(root, element);
            }
            std::cout << "\n";
            // std::cout << root->value << std::endl;
            //print_tree(root, "pre");
        }
        else if(action == "Delete"){
            if(root->left == 0 && root->right == 0){
                delete root;
            }
            delete_tree(root, root);
            std::cout << "The tree has been deleted.\nExiting the program.\n";
            break;
        }
        else if(action == "Rebalance"){
            rebalance_tree(root, nodes);
        }
        else if(action == "Exit") break;
        else if(action == ""){
            std::cout << "\nEnd of file\n";
            break;
        }
        else std::cout << "\nWrong command\n";
        action = "";
    }
}