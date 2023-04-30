#include <iostream>
#include <vector>

#include "BST_Node.h"
#include "BST.h"

using namespace std;

int main()
{
    // Initialisation
    BST_Node* N4 = new BST_Node(nullptr, nullptr, 1);
    BST_Node* N5 = new BST_Node(nullptr, nullptr, 3);
    BST_Node* N6 = new BST_Node(nullptr, nullptr, 5);
    BST_Node* N7 = new BST_Node(nullptr, nullptr, 7);
    BST_Node* N2 = new BST_Node(N4, N5, 2);
    BST_Node* N3 = new BST_Node(N6, N7, 6);
    BST_Node* N1 = new BST_Node(N2, N3, 4);

    // cout << "TEST1 - BST_NODE CLASS" << endl;
    // cout << "Expected: 4 2 6 1 3 5 7" << endl;
    // cout << "Actual:   ";
    // cout << N1->data << " ";
    // cout << N2->data << " ";
    // cout << N3->data << " ";
    // cout << N4->data << " ";
    // cout << N5->data << " ";
    // cout << N6->data << " ";
    // cout << N7->data << " ";
    // cout << endl << endl;

    // Insert test
    BST* BSTBot = new BST(N1);
    cout << "TEST1 - BST CLASS - INSERT()" << endl;
    cout << "Expected: 1 2 3 3 3 4 5 6 7 8" << endl;
    cout << "Actual:   ";
    BSTBot->Insert(8);
    BSTBot->Insert(3);
    BSTBot->Insert(3);
    BSTBot->printTree(2);
    cout << endl << endl;

    // Search test
    cout << "TEST2 - BST CLASS - SEARCH()" << endl;
    cout << "Expected: 1 1 1 1 1 1 0 0 0" << endl;
    cout << "Actual:   ";    
    cout << BSTBot->Search(1) << " ";
    cout << BSTBot->Search(2) << " ";
    cout << BSTBot->Search(3) << " ";
    cout << BSTBot->Search(3) << " ";
    cout << BSTBot->Search(7) << " ";
    cout << BSTBot->Search(8) << " ";
    cout << BSTBot->Search(-5) << " ";
    cout << BSTBot->Search(0) << " ";
    cout << BSTBot->Search(100000000) << " ";
    cout << endl << endl;

    // deleteHelper test
    cout << "TEST3 - BST CLASS - DELETEHELPER()" << endl;
    cout << "Expected: 2 4 6" << endl;
    cout << "Actual:   ";    
    BST_Node* N14 = new BST_Node(nullptr, nullptr, 1);
    BST_Node* N15 = new BST_Node(nullptr, nullptr, 3);
    BST_Node* N16 = new BST_Node(nullptr, nullptr, 5);
    BST_Node* N17 = new BST_Node(nullptr, nullptr, 7);
    BST_Node* N12 = new BST_Node(N14, N15, 2);
    BST_Node* N13 = new BST_Node(N16, N17, 6);
    BST_Node* N11 = new BST_Node(N12, N13, 4);
    BST* BSTBot2 = new BST(N11);
    BST_Node* temp = BSTBot2->DeleteHelper(1);
    cout << temp->data << " ";
    temp = BSTBot2->DeleteHelper(2);
    cout << temp->data << " ";
    temp = BSTBot2->DeleteHelper(7);
    cout << temp->data << " ";
    cout << endl << endl;


        // deleteHelper test
    cout << "TEST3 - BST CLASS - DELETEHELPER()" << endl;
    cout << "Expected: 2 4 6" << endl;
    cout << "Actual:   2 4 5";    
    BSTBot2->Delete(1);
    BSTBot2->Delete(3);
    BSTBot2->Delete(7);
    BSTBot2->Delete(6);
    BSTBot2->printTree(2);
    cout << endl << endl;

    return 0;
}