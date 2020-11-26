#ifndef TREE_H
#define TREE_H

#include<iostream>


class tree
{
public:
    tree();
    //for tree structure
    struct coords;
    struct Node;
    void sibblings(Node *sibbling, coords data, int noOfChild);
    void traverseTilldata(Node *root, coords data, int noOfChild);
    void deallocate(Node *root, coords popedData);
    void deallocateSibs(Node *root);
    void traverse(Node *root);
    Node *root;
};

#endif // TREE_H
