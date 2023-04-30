#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

#include "BST_Node.h"

class BST
{
    BST_Node* root;


public:

    BST();
    BST(BST_Node* input_root);


        
    void Insert(int val);
    bool Search(int val);
    void Delete(int val); 
    BST_Node* DeleteHelper(int val); // searches and returns the parent node of the node you are looking for
    
    /*
    // This is tough. Need to think about how to ammend the tree nodes, if we delete a node, then need to replace it with the right most node from its left subtree
    // also calls search first to see if the value searched for is in the tree
    */

    void printTree(int mode);

    std::vector<int> Preorder();
    std::vector<int> PreorderHelper(std::vector<int> acc, BST_Node* input_traveller);

    std::vector<int> Inorder();
    std::vector<int> InorderHelper(std::vector<int> acc, BST_Node* input_traveller);

    std::vector<int> Postorder();
    std::vector<int> PostorderHelper(std::vector<int> acc, BST_Node* input_traveller);

};


#endif