#ifndef STRUCT_TREE
#define STRUCT_TREE

struct tree{
    int value;
    tree * right;
    tree * left;
    tree * prev;
};

#endif