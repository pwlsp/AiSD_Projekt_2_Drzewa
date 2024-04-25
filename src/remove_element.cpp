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
    std::cout << "Deleted node \"" << element << "\".\n";    
}

void remove_one(tree *&root, int element, tree *&prev)
{
    if(root->left != NULL){
        if(prev->left == root){
            prev->left = root->left;
        }
        else if(prev->right == root){
            prev->right = root->left;
        }
        else{
            std::cout << "Error in \"remove_zero()\" function.\n";
        }
    }
    else if(root->right != NULL){
        if(prev->left == root){
            prev->left = root->right;
            std::cout << prev->left->value << std::endl;
        }
        else if(prev->right == root){
            prev->right = root->right;
        }
        else{
            std::cout << "Error in \"remove_zero()\" function.\n";
        }
    }
    root->left = NULL;
    root->right = NULL;
    root = NULL;
    delete root;
    std::cout << "Deleted node \"" << element << "\".\n";    
}

void remove_two(tree *&root, int element, tree *&prev)
{
}

void remove_element(tree *&root, int element, tree *&prev)
{
    std::cout << "root->value: " << root->value << " element: " << element << " prev->value: " << prev->value << "\n";
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