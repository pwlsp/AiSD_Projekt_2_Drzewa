#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void wstawianie(tree *&root, std::vector<int> data, int a, int z)
{
     int median_index = a + (z - a) / 2;
     // std::cout << median_index << std::endl;

     tree *copy = new tree;
     copy = root;

     tree *nowy = new tree;
     nowy = root;

     while (1)
     {
          if (data[median_index] <= copy->value)
          {
               if (copy->left == 0)
               {
                    tree *tmp = new tree;
                    tmp->value = data[median_index];
                    tmp->left = 0;
                    tmp->right = 0;
                    copy->left = tmp;
                    nowy = copy->left;
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
                    tmp->value = data[median_index];
                    tmp->left = 0;
                    tmp->right = 0;
                    copy->right = tmp;
                    nowy = copy->right;
                    break;
               }
               else
               {
                    copy = copy->right;
               }
          }
     }

     if (z - a == 1)
     {
          wstawianie(nowy, data, z, z);
     }

     else if (z - a >= 2)
     {
          wstawianie(nowy, data, a, median_index - 1);
          wstawianie(nowy, data, median_index + 1, z);
     }
}

void avl(tree *&root, std::vector<int> data)
{
     std::sort(data.begin(), data.end());
     int median_index = (data.size() - 1) / 2;
     root->value = data[median_index];
     root->left = 0;
     root->right = 0;

     tree *copy = new tree;

     std::cout << std::endl
               << "Sorted input data: ";
     for (int i = 0; i < data.size(); i++)
     {
          std::cout << data[i] << " ";
     }

     std::cout << std::endl;

     if (data.size() == 2)
     {
          wstawianie(root, data, 1, 1);
     }

     else if (data.size() >= 3)
     {
          wstawianie(root, data, 0, median_index - 1);
          wstawianie(root, data, median_index + 1, data.size()-1);
     }
     std::cout << "AVL tree has been built." << "\n\n";
}
