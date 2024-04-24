#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void delete_tree(tree *&root)
{
    if (root)
    {
        // print_tree(root,"pre");
        // std::cout << std::endl <<"rut: " << root->value << std::endl;
        if(root->left){
            delete_tree(root->left);
        }
        if(root->right){
            delete_tree(root->right);
        }
        // std::cout << std::endl <<"rut: " << root->value << std::endl;
        // print_tree(root,"pre");
        std::cout << "elo: " << root->value << std::endl;
        delete root;
    }
}