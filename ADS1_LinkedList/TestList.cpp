#include "LinkedList.h"
#include "Node.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{

    // printItems test
    cout << "*printItems()*" << endl << "basic constructor assumed functional" << endl;
    
    // manually creating a linked list
    LinkedList* List1 = new LinkedList();
    Node* Node1 = new Node(1, nullptr);
    Node* Node2 = new Node(2, nullptr);
    Node* Node3 = new Node(3, nullptr);
    Node* Node4 = new Node(4, nullptr);
    Node* Node5 = new Node(5, nullptr);
    Node* Node6 = new Node(6, nullptr);
    List1->head = Node1;
    Node1->setnext(Node2);
    Node2->setnext(Node3);
    Node3->setnext(Node4);
    Node4->setnext(Node5);
    Node5->setnext(Node6);
    
    cout << "Expected: 1 2 3 4 5 6" << endl << "Output:   ";
    List1->printItems();
    cout << endl << endl;





    // complex constructor test
    cout << "*LinkedList(int array[], int size)*" << endl << "printList() is assumed functional" << endl;
    int arr[10]; // list 10 elements long
    int n = 10;
    // insert 10 numbers into array
    for (int i=0; i<n; i++)
    {
        arr[i] = i;
    }

    // creating list and testing the constructor
    LinkedList* List2 = new LinkedList(arr, n);
    cout << "Expected: 0 1 2 3 4 5 6 7 8 9" << endl << "Output:   "; 
    List2->printItems();
    cout << endl << endl;

        

    // All tests from here on assumes printItems() and complex constructor works


    // addFront test
    cout << "*addFront(int newItem)*" << endl;
    int size1 = 5;
    int arr1[5] = {1, 3, 5, 7, 9};
    LinkedList* List3 = new LinkedList(arr1, size1);
    List3->addFront(1);
    cout << "Expected: 1 1 3 5 7 9" << endl << "Output:   ";
    List3->printItems();
    cout << endl << endl;





    // addEnd test
    cout << "*addEnd(int newItem)*" << endl;
    int size2 = 5;
    int arr2[5] = {1, 3, 5, 7, 9};
    LinkedList* List4 = new LinkedList(arr2, size2);
    List4->addEnd(9);
    cout << "Expected: 1 3 5 7 9 9" << endl << "Output:   ";
    List4->printItems();
    cout << endl << endl;





    // addAtPosition test
    cout << "*addAtPosition(int position, int newItem)*" << endl;
    int size3 = 5;
    int arr3[5] = {1, -3, 5, -7, 9};
    LinkedList* List5 = new LinkedList(arr3, size3);
    List5->addAtPosition(-3, 10);
    List5->addAtPosition(1, 20);
    List5->addAtPosition(4, 30);
    List5->addAtPosition(8, 40);
    List5->addAtPosition(10, 50);
    List5->addAtPosition(50, 60);
    cout << "Expected: 20 10 1 30 -3 5 -7 40 9 50 60" << endl << "Output:   ";
    List5->printItems();
    cout << endl << endl;





    // search test
    cout << "*search(int item)*" << endl;
    int size4 = 5;
    int arr4[5] = {1, -3, 5, -7, 9};
    LinkedList* List6 = new LinkedList(arr4, size4);
    cout << "Expected: 1 0 4 5 0" << endl << "Output:   ";
    List6->search(1);
    List6->search(-5);
    List6->search(-7);
    List6->search(9);
    List6->search(1000);
    cout << endl << endl;





    // deleteFront test
    cout << "*deleteFront()*" << endl;
    int size5 = 5;
    int arr5[5] = {1, -3, 5, -7, 9};
    LinkedList* List7 = new LinkedList(arr5, size5);
    cout << "Expected: 5 -7 9 9" << endl << "Output:   ";
    List7->deleteFront();
    List7->deleteFront();
    List7->printItems();    
    List7->deleteFront();
    List7->deleteFront();
    List7->printItems();    
    List7->deleteFront();
    List7->deleteFront();
    List7->printItems();    
    cout << endl << endl;





    // deleteEnd test
    cout << "*deleteEnd()*" << endl;
    int size6 = 5;
    int arr6[5] = {1, -3, 5, -7, 9};
    LinkedList* List8 = new LinkedList(arr6, size6);
    cout << "Expected: 1 -3 5 1" << endl << "Output:   ";
    List8->deleteEnd();
    List8->deleteEnd();
    List8->printItems();    
    List8->deleteEnd();
    List8->deleteEnd();
    List8->printItems();    
    List8->deleteEnd();
    List8->deleteEnd();
    List8->printItems();    
    cout << endl << endl;





    // deletePosition test
    cout << "*deletePosition()*" << endl;
    int size7 = 5;
    int arr7[5] = {1, -3, 5, -7, 9};
    LinkedList* List9 = new LinkedList(arr7, size7);
    cout << "Expected: outside rangeoutside range5 -7 9 outside rangeoutside range-7 outside rangeoutside rangeoutside range-7" << endl << "Output:   ";
    List9->deletePosition(1); // appropriate deletion, 5 elements
    List9->deletePosition(1); // appropriate deletion, 4 elements
    List9->deletePosition(10); // problematic deletion, position>size, 3 elements
    List9->deletePosition(-5); // problematic deletion, negative position, 3 elements
    List9->printItems();    
    List9->deletePosition(3); // appropriate deletion, 3 elements
    List9->deletePosition(10); // problematic deletion, position>size, 2 elements
    List9->deletePosition(-5); // problematic deletion, negative position, 2 elements
    List9->deletePosition(1); // appropriate deletion, 2 elements
    List9->printItems();    
    List9->deletePosition(0); // problematic deletion, position=0, 1 element
    List9->deletePosition(-10); // problematic deletion, negative position, 1 element
    List9->deletePosition(10); // problematic deletion, position>size, 1 element
    List9->printItems();    
    List9->deletePosition(1); // appropriate deletion, 1 element
    List9->deletePosition(1); // problematic deletion, position>size, empty list
    List9->deletePosition(-1); // problematic deletion, negative, empty list
    List9->printItems();
    cout << endl << endl;





    // getItem test
    cout << "*getItem(int position)*" << endl;
    int size8 = 5;
    int arr8[5] = {1, -3, 5, -7, 9};
    LinkedList* List10 = new LinkedList(arr8, size8);
    cout << "Expected: 1 -3 5 -7 9" << endl << "Output:   ";
    List10->getItem(1);
    List10->getItem(2);
    List10->getItem(3);
    List10->getItem(4);
    List10->getItem(5);
    //List9->getItem(5);
    // List9->getItem();
    // List9->getItem();
    cout << endl << endl;





    // ~LinkedList test
    cout << "*~LinkedList(int position)*" << endl;
    int size9 = 5;
    int arr9[5] = {1, -3, 5, -7, 9};
    LinkedList* List11 = new LinkedList(arr9, size9);
    cout << "Expected: END" << endl << "Output:   ";
    List11->~LinkedList();
    List11->printItems();
    cout << "END" << endl << endl;


    return 0;
}
