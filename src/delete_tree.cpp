#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/struct_tree.h"

void delete_tree2(tree *&root, tree *&copy)
{
    if (root)
    {
        delete_tree2(root->left, copy); // usuwamy lewe poddrzewo
        // delete_tree(root->right); // usuwamy prawe poddrzewo
        if (root != copy)
        {
            delete root;
        } // usuwamy sam węzeł
    }
}

void delete_tree(tree *&root)
{
    tree *copy = new tree;
    copy = root;
    delete_tree2(root, copy);
}

// void DFSRelease(AVLNode *v)
// {
//     if (v)
//     {
//         DFSRelease(v->left);  // usuwamy lewe poddrzewo
//         DFSRelease(v->right); // usuwamy prawe poddrzewo
//         delete v;             // usuwamy sam węzeł
//     }
// }