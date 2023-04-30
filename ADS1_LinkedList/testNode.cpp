#include "Node.h"
#include <iostream>

using namespace std;

int main() // conflicts with main.cpp, so make sure we don't compile both main.cpp and testNode.cpp at the same time
{
    // Constructor is assumed functional. We need constructor to work to test anything else, but we cannot test
    // constructor if we cannot assume anything else works. Something has to work.

    // getdata test
    cout << "*getdata() Test*" << endl << "constructor is assumed functional" << endl;
    Node* Node1 = new Node(1, nullptr);
    cout << "Expecting: 1" << endl;
    cout << "Output: " << Node1->getdata() << endl << endl; 


    // getnext test
    cout << "*getnext() Test*" << endl << "constructor is assumed functional" << endl;
    Node* Node3= new Node(3, nullptr);
    Node* Node2= new Node(2, Node3);
    cout << "Expecting: 3" << endl;
    cout << "Output: " << (Node2->getnext())->getdata() << endl << endl;;


    // setdata test
    cout << "*setdata() Test*" << endl << "getdata is assumed functional" << endl;
    Node* Node4 = new Node(0, nullptr);
    Node4->setdata(4);
    cout << "Expecting: 4" << endl;
    cout << "Output: " << Node4->getdata() << endl << endl;


    // setnext test
    cout << "*setnext() Test*" << endl << "getnext is assumed functional"  << endl;
    Node* Node5 = new Node(5, nullptr);
    Node* Node6 = new Node(6, nullptr);
    Node5->setnext(Node6);
    cout << "Expecting: 6" << endl;
    cout << "Output: " << (Node5->getnext())->getdata() << endl;
    

    // tests due to curiosity
    Node* NodeQ = new Node(0, nullptr);
    // cout << "Attempting to print nullptr prints: " << NodeQ->getnext() << endl;
    // cout << "Attempting to access next node's value when current node points to nullptr prints: " << (NodeQ->getnext())->getdata() << endl;


    // How to test if I have the node has the right "next" I want? Just cout << Node.next? and compare?
    // Answer: Yes you don't know the address of the "correct" node so you won't know what you are looking at even if you printed it out and it is correct.
    // So what you do instead is, you use the address in next, to access the data stored in the next node and print THAT out, instead of the printing the address.

    return 0;
}
