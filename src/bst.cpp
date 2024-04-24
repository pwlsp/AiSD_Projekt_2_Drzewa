#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void bst(tree *&root, std::vector<int> data)
{
    root->value = data[0];
    root->left = 0;
    root->right = 0;

    tree *copy = new tree;

    for (int i = 1; i < data.size(); i++)
    {
        copy = root;
        while (1)
        {
            if (data[i] <= copy->value)
            {
                if (copy->left == 0)
                {
                    tree *tmp = new tree;
                    tmp->value = data[i];
                    tmp->left = 0;
                    tmp->right = 0;
                    copy->left = tmp;
                    break;
                }
                else
                {
                    copy = copy->left;
                }
            }
            else
            {
                if (copy->right == 0)
                {
                    tree *tmp = new tree;
                    tmp->value = data[i];
                    tmp->left = 0;
                    tmp->right = 0;
                    copy->right = tmp;
                    break;
                }
                else
                {
                    copy = copy->right;
                }
            }
        }
    }
}