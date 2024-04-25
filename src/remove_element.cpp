#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "../include/struct_tree.h"

void leaf(tree *&parent, tree *&child){
    if(child == parent->left){
        child = NULL; delete child;
        parent->left = NULL;
    }
    else{
        child = NULL; delete child;
        parent->right = NULL;
    }
}

void one_child(tree *&parent, tree *&child){
    if(child == parent->left){
        if(child->left != NULL){
            parent->left = child->left;
            child->left = NULL; delete child;
        }
        else{
            parent->left = child->right;
            child->right = NULL; delete child;
        }
    }
    else{
        if(child->left != NULL){
            parent->right = child->left;
            child->left = NULL; delete child;
        }
        else{
            parent->right = child->right;
            child->right = NULL; delete child;
        }
        
    }
}

void two_children(tree *&child){ 
    tree *replace = child->right; tree *P = child;
    while(replace->left != NULL){
        P = replace;
        replace = replace->left;
    }
    child->value = replace->value;
    if(replace->right == NULL){
        leaf(P, replace);
    }
    else{
        one_child(P, replace);
    }
    //std::cout << "replace: " << replace->value << std::endl;
}  

void remove_element(tree *&root, int element)
{
    if (element < root->value){ //czy idziemy w lewe poddrzewo
        if(root->left != NULL && root->left->value != element) remove_element(root->left, element);
        else if(root->left != NULL && root->left->value == element){//szukany element to lewe dziecko roota
            tree *L = root->left;

            //sprawdzanie ile to cos ma dzieci
            if(L->left != NULL && L->right != NULL) two_children(L);
            else if(L->left != NULL || L->right != NULL) one_child(root, L);
            else leaf(root, L);
        }
        return;
    }
    else if (element > root->value){ //czy idziemy w prawe poddrzewo
        if(root->right != NULL && root->right->value != element) remove_element(root->right, element);
        else if(root->right != NULL && root->right->value == element){//szukany element to prawe dziecko roota
            tree *R = root->right;
            
            //sprawdzanie ile to cos ma dzieci
            if(R->left != NULL && R->right != NULL) two_children(R);
            else if(R->left != NULL || R->right != NULL) one_child(root, R);
            else leaf(root, R);
        }
        return;
    }
    else{
        if(root->left != NULL && root->right != NULL){
            two_children(root);
        }
        else if(root->left != NULL || root->right !=NULL){ //przesuwanie roota na dziecko
            if(root->left != NULL) root = root->left;
            else root = root->right;
        }
        else{
            root = NULL; delete root;
            std::cout << "The tree has been deleted\n.Exiting the program.\n";
            exit(0);
        }
    }
}