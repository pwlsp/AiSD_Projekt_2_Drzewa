#include <iostream>
#include <string>
#include <iomanip>

#include "../include/min_max.h"
#include "../include/print_tree.h"
#include "../include/remove_element.h"
#include "../include/delete_tree.h"
#include "../include/rebalance_tree.h"
#include "../include/struct_tree.h"

void actions(tree *&root, int nodes){
    std::cout << "Actions\n";
    std::string message = "Help\t\tShow this message\nPrint\t\tPrint the tree using In-order, Pre-order, Post-order\nMinMax\t\tShow min and max element\nRemove\t\tRemove elements of the tree\nDelete\t\tDelete whole tree\nExport\t\tExport the tree to tickzpicture\nRebalance\tRebalance the tree\nExit\t\tExits the program (same as ctrl+D)\n";
    std::string action;
    while(std::cin){
        std::cin >> action;
        std::cout << "action> " << action << "\n";
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
            remove_element(root);
        }
        else if(action == "Delete"){
            delete_tree(root);
        }
        else if(action == "Rebalance"){
            rebalance_tree(root, nodes);
        }
        else if(action == "Exit") break;
        else std::cout << "\nWrong command\n";
    }
}