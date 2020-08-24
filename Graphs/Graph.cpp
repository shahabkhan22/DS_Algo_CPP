#include <iostream>
#include "Graph.h"
using namespace std;

Graph::Graph(int v){
    array = new LinkedList[v];
    vertices = v;
}
void Graph::addEdge(int source, int destination){
    if(source < vertices && destination < vertices)
        array[source].insertAtHead(destination);
}

void Graph::printGraph(){
    std::cout<<endl<<"Adjacency List of Directed Graph: "<<endl;
    Node * temp;
    for(int i = 0; i<vertices; i++){
        std::cout<<" | "<<i<<"| => ";
        temp = array[i].getHead();

        while(temp != NULL){
            std::cout<<" ["<<temp->data <<"] ->";
            temp = temp->nextElement;
        }
        std::cout<<"NULL"<<endl;
    }
}

int main(){
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(3,1);
    G.addEdge(4,1);
    G.addEdge(4,3);

    std::cout<<endl;
    G.printGraph();
    return 0;
}