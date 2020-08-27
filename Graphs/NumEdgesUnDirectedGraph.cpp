#include <iostream>
#include "Graph.h"
using namespace std;

//for undirected graph, sum size of all adjacency lists for each vertex
//and divide by 2
//because in undirected graph no. of edges is always even as they are bidirectional
int numEdges(Graph g) {

    int sum = 0;
    Node*temp;
    for (int i = 0; i < g.getVertices(); i++) {

        temp = (g.getArray())[i].getHead();

        while (temp != NULL ) {
            sum++;
            temp = temp->nextElement;
        }
    }
    return sum;
}

int main(){
    Graph g(9);
    g.addEdge(0,2);
    g.addEdge(0,5);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(5,3);
    g.addEdge(5,6);
    g.addEdge(3,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(6,4);
    g.addEdge(7,8);

    Graph g2(7);
    g2.addEdge(1,2);
    g2.addEdge(1,3);
    g2.addEdge(3,4);
    g2.addEdge(3,5);
    g2.addEdge(2,5);
    g2.addEdge(2,4);
    g2.addEdge(4,6);
    g2.addEdge(4,5);
    g2.addEdge(6,5);
    cout<<endl;
    cout<<"G1 Edges: "<<numEdges(g)<<endl;
    cout<<"G2 Edges: "<<numEdges(g2)<<endl;
}