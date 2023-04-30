#include "Node.h"

using namespace std;

// constructor
Node::Node(int data_input, Node* next_input)
{
    data = data_input;
    next = next_input;
}

// getter for data
int Node::getdata()
{
    return data;
}

// getter for next
Node* Node::getnext()
{
    return next;
}

// setter for data
void Node::setdata(int data_input)
{
    data = data_input;
}

// setter for next
void Node::setnext(Node* next_input)
{
    next = next_input;
}