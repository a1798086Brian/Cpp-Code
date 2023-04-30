#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

using namespace std;



LinkedList::LinkedList() // simple/basic constructor
{
    head = nullptr;
    return;
}



LinkedList::LinkedList(int array[], int size) // complex constructor
{
    // create node1
    Node* LastNode = new Node(array[size-1], nullptr);

    // make sure head points to last node.
    head = LastNode;

    Node* TempNode;

    for (int i=(size-2); i>=0; i--)
    {
        // create new node
        TempNode = new Node(array[i], nullptr);
        
        // store new node's reference in previous node's next.
        TempNode->setnext(head);

        head = TempNode;
    }

    return;
}



void LinkedList::addFront(int newItem)
{
    // create a new node containing desired info
    Node* newNode = new Node(newItem, nullptr);

    // ensure new node points to the first node in the list (currently)
    newNode->setnext(head);

    // get head to point to new node
    head = newNode;
    return;
}



void LinkedList::addEnd(int newItem)
{
    Node* LastNode = head; // initialise to start at head

    while ((LastNode->getnext()) != nullptr) // we don't know how many nodes there are.
    {
        LastNode = LastNode->getnext(); // move down the chain.
    } // by the end, LastNode should actually point to the last node of the list

    // create a new node containing desired info
    Node* newNode = new Node(newItem, nullptr);

    // ensure LastNode's next points to new node
    LastNode->setnext(newNode);
    return;
}


void LinkedList::printItems()
{   
    if (head == nullptr) // if the list is empty, print nothing, just return
    {
        return;
    }

    Node* Traveller = head;
    cout << Traveller->getdata() << " ";

    while ((Traveller->getnext()) != nullptr)
    {
        Traveller = Traveller->getnext();
        cout << Traveller->getdata() << " ";
    }

    return; 
}



void LinkedList::addAtPosition(int position, int newItem)
{
    // create a new node containing desired info
    Node* newNode = new Node(newItem, nullptr);

    Node* Traveller = head; // start traveller at the start of list

    if (position <= 1) // we don't even need traveller in this case
    {
        newNode->setnext(head);
        head = newNode;
        return;
    }

    for (int i=1; i<(position-1); i++)
    {
        // traveller travels down one node
        Traveller = Traveller->getnext();

        if (Traveller->getnext() == nullptr)
        {
            break;
        }

    } // by this time this loop finishes, travellor should be one position before the position we want to add a new node
    
    // ensure new node points to next node in chain
    newNode->setnext(Traveller->getnext());
    Traveller->setnext(newNode);

    return;
}



int LinkedList::search(int item)
{
    // create traveller node
    Node* Traveller = new Node(0, nullptr);
    Traveller = head;

    int counter = 1;

    // iterate and compare if data of each node is equal to sought item
    while ((Traveller->getnext()) != nullptr)
    {
        if ((Traveller->getdata()) == item)
        {
            cout << counter << " ";
            return counter; // if found, return counter
        }

        counter++;
        Traveller = Traveller->getnext(); // go down a node
    }

    // compare last node because while loop executes upon reaching last node
    if ((Traveller->getdata()) == item)
    {
        cout << counter << " ";
        return counter;
    }

    cout << "0 ";
    return 0; // if not found
}



void LinkedList::deleteFront()
{
    if (head == nullptr) // no deletion possible with empty list
    {
        return;
    }

    Node* delNode = head; // Hold the address of the first node, which is marked for deletion
    head = head->getnext(); // head now points to second node
    delete delNode; // delete first node
    return;
}



void LinkedList::deleteEnd()
{
    if (head == nullptr) // do nothing if list is empty
    {
        return;
    }

    Node* delNode;
    if (head->getnext() == nullptr) // special case if we only have one node;
    {
        delNode = head;
        head = nullptr;
        delete delNode;
        return;
    }

    Node* Traveller = head;
    while ((Traveller->getnext())->getnext() != nullptr) // travel to second last node    
    {
        Traveller = Traveller->getnext();
    }
    
    delNode = Traveller->getnext();
    Traveller->setnext(nullptr);
    delete delNode; // delete last node

    return;
}



void LinkedList::deletePosition(int position)
{
    if (head == nullptr)
    {
        return; // do nothing
    }

    Node* Traveller = head; // start traveller at the start of list
    Node* delNode; // node marked for deletion

    if (position < 1) // we don't even need traveller in this case
    {
        cout << "outside range";
        return;
    } else if (position == 1)
    {  
        delNode = head;
        head = head->getnext();
        delete delNode;
        return;
    } else if (Traveller->getnext() == nullptr)
    {
        cout << "outside range";
        return;        
    }

    int counter = 1; // represents which node Traveller is currently on, Traveller starts on node 1
    while (Traveller->getnext() != nullptr) // we stop when Traveller becomes last node
    {

        if (counter == (position-1))
        {
            delNode = Traveller->getnext(); 
            Traveller->setnext(delNode->getnext());
            delete delNode;
            return;
        }

        Traveller = Traveller->getnext(); // traveller travels down one node
        counter++;
        
        if (Traveller->getnext() == nullptr) 
        // if we reach the last node but havent deleted anything, this means position is out of bounds
        {
            cout << "outside range";
            return;
        }

    } // by this time this loop finishes, travellor should be one position before the position we want to add a new node
    
    cout << "error";
}





int LinkedList::getItem(int position)
{
    Node* Traveller = head;
    int counter = 1;
    while (Traveller != nullptr)
    {
        if (position == counter)
        {
            cout << Traveller->getdata() << " ";
            return Traveller->getdata();
        }
        counter++;
        Traveller = Traveller->getnext();
    }

    cout << "std::numeric_limits < int >::max() ";
    return std::numeric_limits < int >::max();

    
    //return;
}


LinkedList::~LinkedList()
{
    Node* Traveller = head;
    Node* delNode;

    while (Traveller != nullptr)
    {
        delNode = Traveller;
        Traveller = Traveller->getnext();
        delete delNode;
    }

    head = nullptr;
    return;
}


/*
LinkedList::~LinkedList();
*/