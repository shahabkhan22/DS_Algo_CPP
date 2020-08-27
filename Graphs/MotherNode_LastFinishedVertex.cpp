#include <iostream>
#include "Graph.h"
using namespace std;

//A recursive function to print DFS starting from v
void DFS(Graph g, int node, bool * visited){
    // Mark the current node as visited and print it
    visited[node] = true;

    // Recur for all the vertices adjacent to this vertex
    Node *temp = (g.getArray())[node].getHead();
    while(temp){
        if(visited[temp->data] == false)
            DFS(g, temp->data, visited);
        temp = temp->nextElement;
    }
}

int findMotherVertex(Graph g){
    //visited[] is used for DFS. Initially all are
    // initialized as not visited
    bool * visited = new bool[g.getVertices()];

    //To store last finished vertex (or mother vertex)
    int lastV = 0;

    //Do a DFS traversal and find the last finished vertex
    for(int i = 0; i < g.getVertices(); i++){
        if(visited[i] == false){
            DFS(g, i, visited);
            lastV = i;
        }
    }
    // If there exist mother vertex (or vetices) in given graph, then v must be one (or one of them)
    // Now check if v is actually a mother vertex (or graph has a mother vertex).
    //We basically check if every vertex is reachable from v or not.

    //Reset all values in visited[] as false and do
    //DFS beginning from v to check if all vertices are
    //reachable from it or not.
    for(int i = 0; i < g.getVertices(); i++){
        visited[i] = false;
    }

    DFS(g, lastV, visited);
    for(int i=0; i< g.getVertices(); i++){
        if(visited[i] == false)
            return -1;
    }

    delete[] visited;
    visited = NULL;
    return lastV;
}


int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,0);
    g.addEdge(3,1);

    int motherV = findMotherVertex(g);
    cout << "Mother Vertex : "<<motherV;

    return 0;
}