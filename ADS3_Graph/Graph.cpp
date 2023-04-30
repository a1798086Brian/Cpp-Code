// Adjascency List representation in C++
// Undirected

#include <iostream>
#include <vector>
#include "Graph.h"
#include <array>
#include <queue>

using namespace std;

Graph::Graph() : numVertices(0), adjLists(nullptr) {}

Graph::Graph(int V) : numVertices(V)
{
    // all below code does is dynamically allocate a 2D vector
    vector<vector<int>>* list = new vector<vector<int>>; 
    vector<int>* temp;
    for (int i=0; i<V; i++)
    {
        temp = new vector<int>;  
        list->push_back(*temp);
    }
    adjLists = list;
}

// Add edge
void Graph::addEdge(int source, int destination) { 
    (adjLists->at(source)).push_back(destination);
    (adjLists->at(destination)).push_back(source);
    // adj[source].push_back(destination);
    // adj[destination].push_back(source);    
    return;
}

// Print the graph
void Graph::printGraph() {
    for (int d=0; d < numVertices; ++d) {

        cout << endl << " Vertex " << d << ":";
        
        for (int k=0; k<(adjLists->at(d).size()); k++)
            cout << " -> " << adjLists->at(d).at(k);

        cout << endl;
    }
    return;
}


void Graph::BFS(int startVertex)
{   
    queue<int> q;
    q.push(startVertex);
    vector<bool> visited(numVertices, false);

    int f;

    while (!q.empty())
    {
        f = q.front();
        q.pop();

        cout << f << " ";

        /*
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
        */

        vector<int>::iterator itr;
        for (itr = (adjLists->at(f)).begin(); itr != (adjLists->at(f)).end(); itr++)
        {
            if (!visited[*itr])
            {
                q.push(*itr);
                visited[*itr] = true;
            }
        }

    }
        cout << endl << endl;
        return;    

}



void Graph::BFS2(int startVertex) // editted further to my own liking
{   
    queue<int> q;
    q.push(startVertex);
    vector<bool>* visited = new vector<bool>(numVertices, false);

    int f;

    while (!q.empty())
    {
        f = q.front();
        q.pop();

        cout << f << " ";

        /*
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
        */

        for (int i=0; i<((adjLists.at(f))->size()); i++)
        {
            if (!visited->at(i))
            {
                q.push(visited.at(i)));
                visited[*itr] = true;
            }
        }

    }
        cout << endl << endl;
        return;    

}


/*
void Graph::DFS(int startIndex)
{
    // Mark the current node as visited and
    // print it
    visited[StartIndex] = true;
    cout << StartIndex << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = (adjLists->at(f)).begin(); i != (adjLists->at(f)).end(); ++i)
        if (!visited[*i])
            DFS(*i);

    return;
}
*/



int main() {
    int V = 4; // number of vertices

    // Create a graph
    Graph* Desmos = new Graph(V);

    // Add edges

    Desmos->addEdge(0, 1);
    Desmos->addEdge(0, 2);
    Desmos->addEdge(1, 2);
    Desmos->addEdge(2, 0);
    Desmos->addEdge(2, 3);
    Desmos->addEdge(3, 3);

    //    Desmos->printGraph();

    Desmos->BFS(0);
}