#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ios>
#include <limits>

#include "../include/min_max.h"
#include "../include/print_tree.h"
#include "../include/remove_element.h"
#include "../include/delete_tree.h"
#include "../include/rebalance_tree.h"
#include "../include/struct_tree.h"

void actions(tree *&root, int nodes){
    std::cout << "\nActions\n";
    std::string message = "Help\t\tShow this message\nPrint\t\tPrint the tree using In-order, Pre-order, Post-order\nMinMax\t\tShow min and max element\nRemove\t\tRemove elements of the tree\nDelete\t\tDelete the whole tree\nRebalance\tRebalance the tree\nExit\t\tExit the program (same as ctrl+D)\n";
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, line);
            std::stringstream elements(line);
            std::cout << "remove> ";
            while(elements >> element){
                std::cout << element << " ";
                remove_element(root, element);
            }
            std::cout << "\nGiven elements have been removed successfully.\n";
        }
        else if(action == "Delete"){
            if(root->left == 0 && root->right == 0){
                delete root;
            }
            delete_tree(root, root);
            std::cout << "The tree has been deleted successfully.\nExiting the program...\n";
            break;
        }
        else if(action == "Rebalance"){
            rebalance_tree(root, nodes);
        }
        //else if(action == "Export") export();
        else if(action == "Exit"){
            std::cout << "Exiting the program...\n";
            break;
        }
        else if(action == ""){
            std::cout << "\nEnd of file\nExiting the program...\n";
            break;
        }
        else std::cout << "\nWrong command\n";
        action = "";
    }
}