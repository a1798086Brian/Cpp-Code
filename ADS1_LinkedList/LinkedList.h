#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
    friend class Node;
    
public:
    Node* head;

    LinkedList(); // simple/basic constructor
    LinkedList(int array[], int size); // complex constructor
    void printItems();

    void addFront(int newItem);
    void addEnd(int newItem);
    void addAtPosition(int position, int newItem);
    
    int search(int item); // returns position, given data value. (First instance)

    void deleteFront();
    void deleteEnd();
    void deletePosition(int position);
    
    int getItem(int position); // returns data value given position
    
    
    ~LinkedList();
    
};

#endif