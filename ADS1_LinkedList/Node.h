#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int data_input, Node* next_input);

    // getter for data
    int getdata();

    // getter for next
    Node* getnext();

    // setter for data
    void setdata(int data_input);

    // setter for next
    void setnext(Node* next_input);
    

};

#endif