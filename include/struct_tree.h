#ifndef STRUCT_TREE
#define STRUCT_TREE

struct tree{
    int value;
    int bf; //wspl rownowagi
    tree * right;
    tree * left;
    tree * prev;
};

#endif