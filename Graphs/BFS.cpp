#include <iostream>
#include "Graph.h"
using namespace std;

void bfsTraversal_Helper(Graph g, int source, bool * visited, string &result){

    if(g.getVertices() < 1)
        return ;

    //Queue created for BFS and source enQueued in it
    myQueue queue(g.getVertices());

    queue.enQueue(source);
    visited[source] = true;
    int current_node;

    //Traverse while queue is not empty
    while(!queue.isEmpty()){
        current_node = queue.deQueue(); //Dequeue vertex and add it to result
        result += to_string(current_node);

        //Get adjacent vertices to the current_node from array
        //if they are not already visited then enQueue them into the queue
        Node *temp = (g.getArray())[current_node].getHead();

        while(temp != NULL){
            if(!visited[temp->data]){
                queue.enQueue(temp->data);
                visited[temp->data] = true; //visit the current node
            }
            temp = temp->nextElement;
        }
    }
}

string bfsTraversal(Graph g){
    string result = "";

    //Bool array to hold the history of visited nodes
    //Make a node visited whenever it is pushed into the stack
    bool * visited = new bool[g.getVertices()];
    for(int i=0; i < g.getVertices(); i++){
        if(!visited[i])
            bfsTraversal_Helper(g, i, visited, result);
    }
    delete[] visited;
    visited = NULL;
    return result;
}


int main(){
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);

    cout << endl << bfsTraversal(g) << endl;
}