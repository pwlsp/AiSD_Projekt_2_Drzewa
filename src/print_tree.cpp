#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

std::string print_tree(){

    std::cout << "ok\n";
    std::stringstream resultStream;
    resultStream << "The tree has been printed\n";
    return resultStream.str();
}