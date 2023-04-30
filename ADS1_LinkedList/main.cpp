#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
        
    // initialization
    string FUNCTION_CODE;

    string temp;
    char temp2;
    vector<string> inputs_vec;



    // passing input into ss
    string input2;
    getline(cin, input2);
    stringstream ss(input2);



    // passing ss into a vector
    while (ss >> temp)
    {   
        inputs_vec.push_back(temp);
    }
    


    // passing last three vector inputs into variables separately
    int input_size = inputs_vec.size();
    temp = inputs_vec.at(input_size-2);
    int param1 = stoi(temp);
    temp = inputs_vec.at(input_size-1);
    int param2 = stoi(temp);
    FUNCTION_CODE = inputs_vec.at(input_size-3);



    // converting remaining vector inputs to C array
    inputs_vec.pop_back();
    inputs_vec.pop_back();
    inputs_vec.pop_back();
    int vect_size = inputs_vec.size();
    int arr[vect_size];
    for (int i=0; i<vect_size; i++)
    {
        // temp = inputs_vec.at(i);
        // temp2 = temp[0];
        // arr[i] = temp2 - '0';

        temp = inputs_vec.at(i);
        arr[i] = stoi(temp);
    }
    


    // converting array of numbers to linked list
    LinkedList* list = new LinkedList(arr, vect_size);



// void addFront(int newItem);
//     void addEnd(int newItem);
//     void addAtPosition(int position, int newItem);
    
//     int search(int item); // returns position, given data value. (First instance)

//     void deleteFront();
//     void deleteEnd();
//     void deletePosition(int position);
    
    int getItem(int position);

    if (FUNCTION_CODE == "AF")
    {
        list->addFront(param1);


    } else if(FUNCTION_CODE == "AE")
    {
        list->addEnd(param1);


    } else if(FUNCTION_CODE == "AP")
    {
        list->addAtPosition(param1, param2);


    } else if(FUNCTION_CODE == "S")
    {
        int temp1 = list->search(param1);


    } else if(FUNCTION_CODE == "DF")
    {
        list->deleteFront();


    } else if(FUNCTION_CODE == "DS")
    {
        list->deleteEnd();


    } else if(FUNCTION_CODE == "DP")
    {
        list->deletePosition(param1);


    } else if(FUNCTION_CODE == "GI")
    {
        int temp2 = list->getItem(param1);
    } else
    {
        cout << "Invalid Function Code" << endl;
    }




    list->printItems();
    cout << endl;

    return 0;
}
