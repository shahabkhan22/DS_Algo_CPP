#include <iostream>
#include "Graph.h"
using namespace std;

bool detectCycleRec(Graph g, int i, bool* visited, bool* recNodes){

    if(!visited[i] == false){

        visited[i] = true;
        recNodes[i] = true;


        int adjacent;
        Node * adjacentNode = (g.getArray())[i].getHead();
        while(adjacentNode != NULL){
            adjacent = adjacentNode->data;
            if((!visited[adjacent]) && detectCycleRec(g, adjacent, visited, recNodes))
                return true;
            else if(recNodes[adjacent])
                return true;
            adjacentNode = adjacentNode->nextElement;
        }
    }

    recNodes[i] = false;
    return false;
}

bool detectCycle(Graph g){
    int num_of_vertices = g.getVertices();

    bool* visited = new bool[num_of_vertices];

    bool* recNodes = new bool[num_of_vertices];

    for(int i = 0; i < num_of_vertices; i++){
        if(detectCycleRec(g, i, visited, recNodes))
            return true;
    }
    return false;
}

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(4,5);
    cout<<detectCycle(g)<<endl;
    g.addEdge(5,3);
    cout<<detectCycle(g)<<endl;
    return 0;
}