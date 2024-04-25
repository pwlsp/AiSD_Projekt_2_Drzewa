#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void delete_tree(tree *&root, tree *korzen)
{
    if (root)
    {
        if(root->left){
            delete_tree(root->left, korzen);
            root->left = NULL;
        }
        if(root->right){
            delete_tree(root->right, korzen);
            root->right = NULL;
        }
        std::cout << "deleting root \"" << root->value << "\"" << std::endl;
        if(root != korzen){
            delete root;
        }
        else{
            root = NULL;
        }
    }
}