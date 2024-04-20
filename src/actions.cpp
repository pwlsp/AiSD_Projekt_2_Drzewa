#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/min_max.h"
#include "../include/print_tree.h"
#include "../include/remove_element.h"
#include "../include/delete_tree.h"
#include "../include/rebalance_tree.h"
#include "../include/struct_tree.h"

std::string actions(tree *root){
    std::string message = "Help\tShow this message\nPrint\tPrint the tree using In-order, Pre-order, Post-order\nMinMax\tShow min and max element\nRemove\tRemove elements of the tree\nDelete\tDelete whole tree\nExport\tExport the tree to tickzpicture\nRebalance\tRebalance the tree\nExit\tExits the program (same as ctrl+D)\n";
    
    std::string action;
    std::cin.sync();
    std::cin >> action;
    std::cout << "Weszlo";
    while(std::cin){
        if(action == "Help"){
           std::cout << message;
        }
        else if(action == "Print"){
            std::cout << print_tree(root);
        }
        else if(action == "MinMax"){
            std::cout << min_max(root);
        }
        else if(action == "Remove"){
            std::cout << remove_element(root);
        }
        else if(action == "Delete"){
            std::cout << delete_tree(root);
        }
        else if(action == "Rebalance"){
            std::cout << rebalance_tree(root);
        }
        else std::cout << "\nWrong command\n";
        std::cout << "action> ";
        std::cin >> action;
    }
    std::cout << "\n";
    std::stringstream resultStream;
    resultStream << "";
    return resultStream.str();
}