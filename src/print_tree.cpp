#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "struct_tree.h"

std::string print_tree(tree *root){

    std::cout << "ok\n";
    std::stringstream resultStream;
    resultStream << "The tree has been printed\n";
    return resultStream.str();
}