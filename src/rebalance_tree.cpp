#include <iostream>
#include <cmath>
#include <string>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void winorosl(tree *&root){
    tree *L, *R; 
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

        tmp = NULL; delete tmp;
    }
    if(root->right != NULL) winorosl(root->right);
    L = NULL; delete L;
    R = NULL; delete R;
}

void turn_left(tree *&root){
    tree *L, *R;
    L = root->left;
    R = root->right;
    tree *tmp = new tree; tree *tmp2; tmp2 = new tree;
    tmp2->value = root->value;
    tmp2->left = L;
    tmp2->right = R->left;
    tmp->value = R->value;
    tmp->right = R->right;
    tmp->left = tmp2;
    root = tmp;
    L = NULL; delete L;
    R = NULL; delete R;
    tmp = NULL; delete tmp;
    if(root->right != NULL) turn_left(root->right);
}

void balansowanie(tree *&root, int N){
    
    int x = N + 1 - pow(2, log2(N+1));
    int y = N - x;
    while(y > 1){
        turn_left(root);
        y /= 2;
    }
}

void rebalance_tree(tree *&root, int nodes){

    //  int n = 8; int tab[n] = {5,3,2,4,8,9,6,7};
    //     tree * root = new tree;
        
    //     int root_value = tab[0];
    //     root->value = root_value;
    //     root->left = NULL;
    //     root->right = NULL;
    //     tree * tmp;
    //     tree * node;
    //     for(int i=1;i<n;i++){
    //             int a = tab[i];
    //             node = new tree;
    //             node->left = NULL;
    //             node->right = NULL;
    //             node->value = a;
    //             tmp = root;
    //             while(true){
    //                     if(a<tmp->value){
    //                             if(tmp->left == NULL){
    //                                     tmp->left = node;
    //                                     node->prev = tmp;
    //                                     break;
    //                             }else{
    //                                     tmp = tmp->left;
    //                             }
    //                     }else{
    //                             if(tmp->right == NULL){
    //                                     tmp->right = node;
    //                                     node->prev = tmp;
    //                                     break;
    //                             }else{
    //                                     tmp = tmp->right;
    //                             }        
    //                     }
    //             }        
    //     }


    print_tree(root, "pre");
    winorosl(root);
    balansowanie(root, nodes);
    print_tree(root, "pre");

}