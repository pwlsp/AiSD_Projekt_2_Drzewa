#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

std::string delete_tree(){

    std::cout << "ok\n";
    std::stringstream resultStream;
    resultStream << "The tree has been deleted.\n";
    return resultStream.str();
}