#include <iostream>
#include <vector>

#include "BST.h"

using namespace std;

BST::BST() : root(nullptr) {}

BST::BST(BST_Node* input_root) : root(input_root) {}




BST_Node* BST::DeleteHelper(int val)
{
    BST_Node* trav = root; // travelling node

    BST_Node* travParent = nullptr; // empty trees or single node trees are ignored in this function, that is taken care of in Delete()

    while ((trav->left != nullptr) || (trav->right != nullptr)) // need to reach leaf node
    {
        if (trav->data == val) return travParent;

        if (trav->data <= val) {
            travParent = trav;
            trav = trav->right;
        } else
        {
            travParent = trav;
            trav = trav->left;
        }
    }

    if (trav->data == val) return travParent;

    cout << "Error" << endl;
    return travParent;

}




void BST::Delete(int val)
{
    if (Search(val) == false)  // if searched item DNE
    {
        cout << "Deletion failed, value does not exist" << endl;
        return; 
    }



    if (root == nullptr) return; // empty tree

    if ((root->data == val) && (root->left == nullptr) && (root->right == nullptr)) // if root == value, single node trees
    {
        delete root;
        root = nullptr;
        return;
    } else if ((root->left == nullptr) && (root->right == nullptr)) return; // if root != value, single node tree


    BST_Node* DNP;  // Deleted Node's Parent, which will eventually become the parent of the node to be deleted
    BST_Node* RNP;  // Replacement Node's Parent, which will eventually become the parent of 
                                      // the right most leaf of delNode's left subtree
    BST_Node* delNode;


    // search tree to find DNP
    DNP = DeleteHelper(val);

    // duplicate delNodeParent
    BST_Node* DNP_replica = DNP;
        
    // use duplicate to find RNP
    RNP = DNP_replica;
    DNP_replica = DNP_replica->left;
    
    while (DNP_replica->right != nullptr)
    {
        RNP = DNP_replica;
        DNP_replica = DNP_replica->right;
    }


    // Get DNP's left/right points to RNP's right
        // need to do a quick check to know if it's left of right
    bool lr; // true means left, false means right
    if ((DNP->left)->data == val) 
    {
        DNP->left = RNP->right; 
    } else if ((DNP->right)->data == val)
    {
        DNP->right = RNP->right;
    } 


    // Get RNP's child points to the same nodes as DNP's child does
    if ((DNP->left)->data == val) 
    {
        RNP->right->left = DNP->left->left;
        RNP->right->right = DNP->left->right;

    } else if ((DNP->right)->data == val)
    {
        RNP->right->left = DNP->right->left;
        RNP->right->right = DNP->right->right;
    } 

    // delete RNP's child
    delete (RNP->right);


    // set RNP's pointers to nullptr, it no longer has any leaves
    RNP->right = nullptr;

    return;
}







bool BST::Search(int val)
{
    BST_Node* trav = root; // travelling node

    while ((trav->left != nullptr) || (trav->right != nullptr)) // need to reach leaf node
    {
        if (trav->data == val) return true;

        if (trav->data <= val) {
            trav = trav->right;
        } else
        {
            trav = trav->left;
        }
    }

    if (trav->data == val) return true;

    return false;
}



void BST::Insert(int val)
{
    BST_Node* trav = root; // travelling node

    while ((trav->left != nullptr) || (trav->right != nullptr)) // need to reach leaf node
    {
        if (trav->data <= val) {
            trav = trav->right;
        } else
        {
            trav = trav->left;
        }
    }

    // we reached an appropriate leaf node
    BST_Node* NewNode = new BST_Node(val);

    if (trav->data <= val) trav->right = NewNode; else trav->left = NewNode;

    return;
}





void BST::printTree(int mode)
{
    BST_Node* trav = root; // travelling node
    vector<int> res; // result

    if (mode == 1)
    {
        res = Preorder(); 
    } else if (mode == 2)
    {
        res = Inorder();
    } else if (mode == 3)
    {
        res = Postorder();
    } else 
    {
        cout << "Invalid Input. Input must be 1, 2, or 3." << endl;
    }

    // prints tree in chosen order
    vector<int>::iterator itr = res.begin();
    for (itr; itr<res.end(); itr++) cout << *itr << " ";
    return;
}





std::vector<int> BST::Preorder()
{
    BST_Node* trav = root; // travelling node
    vector<int> res; // result

    res = PreorderHelper(res, trav);
    
    return res;
}

std::vector<int> BST::PreorderHelper(std::vector<int> acc, BST_Node* input_traveller)
{
    // base case
    acc.push_back(input_traveller->data);

    // travel left
    if (input_traveller->left != nullptr) acc = PreorderHelper(acc, input_traveller->left);

    // travel right
    if (input_traveller->right != nullptr) acc = PreorderHelper(acc, input_traveller->right);

    // return
    return acc;
}



vector<int> BST::Inorder()
{
    BST_Node* trav = root; // travelling node
    vector<int> res; // result

    res = InorderHelper(res, trav);
    
    return res;
}

vector<int> BST::InorderHelper(vector<int> acc, BST_Node* input_traveller)
{


    // travel left
    if (input_traveller->left != nullptr) acc = InorderHelper(acc, input_traveller->left);

    // base case
    acc.push_back(input_traveller->data);

    // travel right
    if (input_traveller->right != nullptr) acc = InorderHelper(acc, input_traveller->right);

    // return
    return acc;
}





std::vector<int> BST::Postorder()
{
    BST_Node* trav = root; // travelling node
    vector<int> res; // result

    res = PostorderHelper(res, trav);
    
    return res;
}

std::vector<int> BST::PostorderHelper(std::vector<int> acc, BST_Node* input_traveller)
{
    // travel left
    if (input_traveller->left != nullptr) acc = PostorderHelper(acc, input_traveller->left);

    // travel right
    if (input_traveller->right != nullptr) acc = PostorderHelper(acc, input_traveller->right);

    // base case
    acc.push_back(input_traveller->data);

    // return
    return acc;
}