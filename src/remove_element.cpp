#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "struct_tree.h"

std::string remove_element(tree *root){

    std::cout << "ok\n";
    std::stringstream resultStream;
    resultStream << "Elements have been removed\n";
    return resultStream.str();
}