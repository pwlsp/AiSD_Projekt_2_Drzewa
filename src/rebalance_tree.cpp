#include <iostream>
#include <cmath>
#include <string>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

void winorosl(tree *&root){
    
    while(root->left != NULL){
        tree *tmp; tmp = new tree; //nowe prawe poddrzewo
        tmp->value = root->value;
        tmp->left = root->left->right;
        tmp->right = root->right;

        root->value = root->left->value;
        root->right = tmp;
        root->left = root->left->left;
    }
    if(root->right != NULL) winorosl(root->right);
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
    if(root->right != NULL and root->right->right != NULL) turn_left(root->right);
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
    winorosl(root);
    balansowanie(root, nodes);
    std::cout << "The tree has been rebalanced successfully.\n";
    //print_tree(root, "pre");

}