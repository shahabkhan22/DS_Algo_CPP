#include <iostream>
#include "Graph.h"
using namespace std;

bool checkCycle(Graph g, int vertex, bool* visited, int parent){
    //Mark the current vertex as visited
    visited[vertex] = true;

    //Recursive calls for all vertices adjacent to this vertex
    Node * temp = (g.getArray())[vertex].getHead();

    while(temp != NULL){
        //If an adjacent vertex is not visited, make recursive call on adjacent vertex
        if(!visited[temp->data]){
            if(checkCycle(g, temp->data, visited, vertex))
                return true;
        }
        //If an adjacent is visited and not parent of current, then it is cycle
        else if(temp->data != parent)
            return true;

        temp = temp->nextElement;
    }
    return false;

}


bool isTree(Graph g){
    bool * visited = new bool[g.getVertices()];

    //set all vertex visited as false
    for(int i=0; i < g.getVertices(); i++)
        visited[i] = false;

    if(checkCycle(g, 0, visited, -1))
        return false;

    for(int i=0; i < g.getVertices(); i++){
        if(!visited[i])
            return false;
    }

    delete[] visited;
    visited = NULL;
    return false;
}

int main() {
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,4);


    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    bool isT1 = isTree(g);
    bool isT2 = isTree(2);

    cout<<endl;
    cout << isT1<< endl;
    cout << isT2<< endl;

}
