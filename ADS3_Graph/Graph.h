#ifndef GRAPH_H
#define GRAPH_H

class Graph 
{
    int numVertices;
    std::vector<std::vector<int>>* adjLists;
    
public:
    Graph();
    Graph(int V);
    void addEdge(int src, int dest);
    // void deleteEdge(int src, int dest);
    // bool isConnected(int src, int dest);
    void printGraph();

    void BFS(int startVertex);
};

#endif