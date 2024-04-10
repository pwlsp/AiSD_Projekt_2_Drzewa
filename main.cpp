#include <iostream>
#include <string>

//#include "avl.h"
//#include "bst.h"
//#include "print_tree.h"
//#include "remove_element.h"
//#include "delete_tree.h"
//#include "rebalance.h"

int main() {

    std::string message = "Help\tShow this message\nPrint\tPrint the tree usin In-order, Pre-order, Post-order\nRemove\tRemove elements of the tree\nDelete\tDelete whole tree\nExport\tExport the tree to tickzpicture\nRebalance\tRebalance the tree\nExit\tExits the program (same as ctrl+D)\n";

    std::string action;
    std::cout << "action>";
    std::cin >> action;
    if(action == "Help"){
        std::cout << message;
    }
    else if(action == "Print"){
        printing();
    }
    else if(action == "Remove"){
        remove_element();
    }
    else if(action == "Delete"){
        delete_tree();
    }
    else if(action == "Rebalance"){
        rebalance_tree();
    }
    else if(action == "Exit"){
        return 0;
    }
}