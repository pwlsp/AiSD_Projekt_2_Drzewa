#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "../include/struct_tree.h"

int min_element(tree *&root){
    int mini;
    tree *L = root;
    if(L->left == NULL) return L->value;
    while(L->left != NULL){
        std::cout << L->value << " ";
        L = L->left;
    }
    mini = L->value;
    L = NULL; delete L;
    std::cout << "wynik ";
    return mini;
}

int max_element(tree *&root){
    int maxi;
    tree *R = root;
    if(R->right == NULL) return R->value;
    while(R->right != NULL){
        R = R->right;
    }
    maxi = R->value;
    R = NULL; delete R;
    return maxi;
}

void min_max(tree *root){
//  int n = 8; int tab[n] = {1,5,4,8,9,6,7,9};
//         tree * root = new tree;
        
//         int root_value = tab[0];
//         root->value = root_value;
//         root->left = NULL;
//         root->right = NULL;
//         tree * tmp;
//         tree * node;
//         for(int i=1;i<n;i++){
//                 int a = tab[i];
//                 node = new tree;
//                 node->left = NULL;
//                 node->right = NULL;
//                 node->value = a;
//                 tmp = root;
//                 while(true){
//                         if(a<tmp->value){
//                                 if(tmp->left == NULL){
//                                         tmp->left = node;
//                                         node->prev = tmp;
//                                         break;
//                                 }else{
//                                         tmp = tmp->left;
//                                 }
//                         }else{
//                                 if(tmp->right == NULL){
//                                         tmp->right = node;
//                                         node->prev = tmp;
//                                         break;
//                                 }else{
//                                         tmp = tmp->right;
//                                 }        
//                         }
//                 }        
//         }


    std::cout << "Min: " << min_element(root) << "\n";
    std::cout << "Max: " << max_element(root) << "\n";
    // std::stringstream resultStream;
    // resultStream << "Min and max elements have been found\n";
    // return resultStream.str();
}