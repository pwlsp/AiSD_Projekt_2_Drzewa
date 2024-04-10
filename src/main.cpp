#include <iostream>

#include "min_max.h"
#include "avl.h"
#include "bst.h"
#include "print_tree.h"
#include "remove_element.h"
#include "delete_tree.h"
#include "rebalance_tree.h"

int main() {

    std::string message = "Help\tShow this message\nPrint\tPrint the tree usin In-order, Pre-order, Post-order\nMinMax\tShow min and max element\nRemove\tRemove elements of the tree\nDelete\tDelete whole tree\nExport\tExport the tree to tickzpicture\nRebalance\tRebalance the tree\nExit\tExits the program (same as ctrl+D)\n";

    std::string action;
    std::cout << "action> ";
    std::cin >> action;
    while(std::cin){
    if(action == "Help"){
        std::cout << message;
    }
    else if(action == "Print"){
        std::cout << print_tree();
    }
    else if(action == "MinMax"){
        std::cout << min_max();
    }
    else if(action == "Remove"){
        std::cout << remove_element();
    }
    else if(action == "Delete"){
        std::cout << delete_tree();
    }
    else if(action == "Rebalance"){
        std::cout << rebalance_tree();
    }
    else if(action == "Exit"){
        return 0;
    }
    else std::cout << "Wrong command\n";
    std::cout << "action> ";
    std::cin >> action;
    }
    std::cout << "\n";
    return 0;
}