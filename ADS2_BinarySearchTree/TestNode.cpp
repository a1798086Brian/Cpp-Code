#include <iostream>
#include <vector>

#include "BST_Node.h"

using namespace std;

int main() 
{
    // Testing Nodes
    BST_Node* N4 = new BST_Node(nullptr, nullptr, 1);
    BST_Node* N5 = new BST_Node(nullptr, nullptr, 3);
    BST_Node* N6 = new BST_Node(5);
    BST_Node* N7 = new BST_Node(7);
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

    return 0;
}