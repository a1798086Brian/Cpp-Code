#include <iostream>
#include "BST.h"
#include "BST_Node.h"

using namespace std;

void test(int val)
{
    cout << val << endl;
    return;
}

int main() 
{
    // Testing Nodes
    BST_Node* N4 = new BST_Node(nullptr, nullptr, 1);
    BST_Node* N5 = new BST_Node(nullptr, nullptr, 3);
    BST_Node* N6 = new BST_Node(nullptr, nullptr, 5);
    BST_Node* N7 = new BST_Node(nullptr, nullptr, 7);
    BST_Node* N2 = new BST_Node(N4, N5, 2);
    BST_Node* N3 = new BST_Node(N6, N7, 6);
    BST_Node* N1 = new BST_Node(N2, N3, 4);

    cout << "TEST1 - BST_NODE CLASS" << endl;
    cout << "Expected: 4 2 6 1 3 5 7" << endl;
    cout << "Actual:   ";
    cout << N1->data << " ";
    cout << N2->data << " ";
    cout << N3->data << " ";
    cout << N4->data << " ";
    cout << N5->data << " ";
    cout << N6->data << " ";
    cout << N7->data << " ";
    cout << endl << endl;

    // build this:
    BST* BSTBot = new BST(N1);
    cout << "TEST2 - BST CLASS - INORDER()" << endl;
    cout << "Expected: 1 2 3 4 5 6 7" << endl;
    cout << "Actual:   ";    
    BSTBot->printTree(2);


    // Then test BST in order traversal



    // Then divide all my test cases over multiple files and then create a makefile. 

    // then continue coding

    cout << "Testing Function" << endl;
    test(3.3);


    return 0;
}