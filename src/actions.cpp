#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ios>
#include <limits>

#include "../include/min_max.h"
#include "../include/print_tree.h"
#include "../include/remove_element.h"
#include "../include/delete_tree.h"
#include "../include/rebalance_tree.h"
#include "../include/struct_tree.h"

void actions(tree *root){

    print_tree(root);
    std::string message = "Help\tShow this message\nPrint\tPrint the tree using In-order, Pre-order, Post-order\nMinMax\tShow min and max element\nRemove\tRemove elements of the tree\nDelete\tDelete whole tree\nExport\tExport the tree to tickzpicture\nRebalance\tRebalance the tree\nExit\tExits the program (same as ctrl+D)\n";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string action;
    std::cin >> action;
    while(std::cin){
        std::cout << "Weszlo";
        if(action == "Help"){
           std::cout << message;
        }
        else if(action == "Print"){
            print_tree(root);
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
            rebalance_tree(root);
        }
        else std::cout << "\nWrong command\n";
        std::cout << "action> ";
        std::cin >> action;
    }
}