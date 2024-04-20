#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void winorosl(tree *&root){
    tree *tmp, *L, *R; 
    //obracanie w prawo
    while(root->left != NULL){
        L = root->left;
        R = root->right;
        //std::cout << root->value << " L:" << L->value << " R:" << R->value << "\n";
        tree *tmp;
        tmp = new tree;
        tmp->value = root->value;
        tmp->right = R;
        tmp->left = L->right;
        root->value = L->value;
        root->right = tmp;
        root->left = L->left;
    }
    if(root->right != NULL) winorosl(root->right);
}

void balansowanie(tree *&root){

}

void rebalance_tree(tree *&r){

     int n = 8; int tab[n] = {5,3,2,4,8,9,6,7};
        tree * root = new tree;
        
        int root_value = tab[0];
        root->value = root_value;
        root->left = NULL;
        root->right = NULL;
        tree * tmp;
        tree * node;
        for(int i=1;i<n;i++){
                int a = tab[i];
                node = new tree;
                node->left = NULL;
                node->right = NULL;
                node->value = a;
                tmp = root;
                while(true){
                        if(a<tmp->value){
                                if(tmp->left == NULL){
                                        tmp->left = node;
                                        node->prev = tmp;
                                        break;
                                }else{
                                        tmp = tmp->left;
                                }
                        }else{
                                if(tmp->right == NULL){
                                        tmp->right = node;
                                        node->prev = tmp;
                                        break;
                                }else{
                                        tmp = tmp->right;
                                }        
                        }
                }        
        }


    print_tree(root, "pre");
    winorosl(root);
    balansowanie(root);
    print_tree(root, "pre");

}