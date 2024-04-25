#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/struct_tree.h"

void remove_zero(tree *&root, int element, tree *&prev)
{
    if(prev->left == root){
        prev->left = NULL;
    }
    else if(prev->right == root){
        prev->right = NULL;
    }
    else{
        std::cout << "Error in \"remove_zero()\" function.\n";
    }

    delete root;
}

void remove_one(tree *&root, int element, tree *&prev)
{
}

void remove_two(tree *&root, int element, tree *&prev)
{
}

void remove_element(tree *&root, int element, tree *&prev)
{
    std::cout << "root: " << root << "\nelement: " << element << "\nprev: " << prev << "\n";
    if (element < root->value)
    {
        remove_element(root->left, element, root);
        return;
    }
    else if (element > root->value)
    {
        remove_element(root->right, element, root);
        return;
    }
    else
    {
        if (root->left && root->right)
        {
            remove_two(root, element, prev);
        }
        else if (root->left || root->right)
        {
            remove_one(root, element, prev);
        }
        else
        {
            remove_zero(root, element, prev);
        }

        return;
    }
}