#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include <vector>

class BST_Node 
{

public:
    BST_Node* left;
    BST_Node* right;
    int data;

    BST_Node();
    BST_Node(int input_data);
    BST_Node(BST_Node* input_left, BST_Node* input_right, int input_data);
};


#endif 