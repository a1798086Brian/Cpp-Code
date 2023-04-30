#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int V = 3;

    vector<vector<int>>* list = new vector<vector<int>>;
    vector<int>* temp;

    /*
    for (int i=0; i<V; i++)
    {
        temp = new vector<int>();
        list->push_back(*temp);
    }
    */

    for (int i=0; i<V; i++)
    {
        temp = new vector<int>;
    
        for (int j=0; j<3; j++)
        {
            temp->push_back(j);
        }
    
        list->push_back(*temp);
    }

    cout << "Expected: 0 1 2 0 1 2 0 1 2" << endl;
    cout << "Actual:   ";

    for (int i=0; i<V; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << (list->at(i)).at(j) << " ";
        }
    }
    cout << endl << endl;





    vector<bool>* test = new vector<bool>(5, true);
    
    cout << "Expected: 1 1 1 1 1" << endl;
    cout << "Actual:   ";
    for (int i=0; i<test->size(); i++) cout << test->at(i) << " ";
    cout << endl << endl;

    return 0;
}
