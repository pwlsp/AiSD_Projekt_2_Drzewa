#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
// #include <vector>

#include "../include/struct_tree.h"
#include "../include/print_tree.h"

std::string tikz_create(tree *&root)
{
    std::string l_str, r_str;
    if(root->left == NULL && root->right == NULL){
        return("\\node{" + std::to_string(root->value) + "}");
    }
    if(root->left){
        l_str = "child {" + tikz_create(root->left) + "}";
    }
    else l_str = "child{missing}";
    if(root->right){
        r_str = "child {" + tikz_create(root->right) + "}";
    }
    else r_str = "child{missing}";

    return("\\node {" + std::to_string(root->value) + "} " + l_str + " "+ r_str);
}

std::string tikz(tree *&root)
{
    std::string latex = "\\begin{tikzpicture} [level distance=10mm,every node/.style={fill=red!60,circle,inner sep=1pt},\nlevel 1/.style={sibling distance=100mm,nodes={fill=red!50}},\nlevel 2/.style={sibling distance=45mm,nodes={fill=red!40}},\nlevel 3/.style={sibling distance=22mm,nodes={fill=red!30}},\nlevel 4/.style={sibling distance=10mm,nodes={fill=red!25}},\nlevel 5/.style={sibling distance=5mm,nodes={fill=red!20}},\nlevel 6/.style={sibling distance=5mm,nodes={fill=red!15}},\nlevel 7/.style={sibling distance=5mm,nodes={fill=red!10}},\nlevel 8/.style={sibling distance=5mm,nodes={fill=red!5}},\nlevel 9/.style={sibling distance=5mm,nodes={fill=red!5}},\nlevel 10/.style={sibling distance=5mm,nodes={fill=red!5}}]\n" + tikz_create(root) + "\n\\end{tikzpicture}";
    return(latex);
}