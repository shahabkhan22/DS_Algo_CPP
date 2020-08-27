#include <iostream>
#include "Graph.h"
using namespace std;

int findMin(Graph g, int source, int destination){
    if(source == destination)
        return 0;

    int result = 0;
    int num_of_vertices = g.getVertices();

    //Bool array of visited vertices
    bool * visited = new bool[num_of_vertices];

    //For keeping track of distance of current_node from source
    int * distance = new int[num_of_vertices];

    //Queue for BFS Traversal and enqueue source into it
    myQueue queue(num_of_vertices);

    queue.enQueue(source);
    visited[source] = true;
    int current_node;
    Node * temp;

    //Traverse the queue till it is not empty
    while(!queue.isEmpty()){

        //Dequeue a vertec from queue and add it to result
        current_node = queue.deQueue();

        //Get adjacent vertices to the current node from the array
        //If they are not already visited then enqueue them in the queue
        //update their distance from source by adding 1 in the current_node
        temp = (g.getArray())[current_node].getHead();

        while(temp != NULL){
            if(!visited[temp->data]){
                queue.enQueue(temp->data);
                visited[temp->data] = true;
                distance[temp->data] = distance[current_node] + 1;
            }
            if(temp->data == destination)
                return distance[destination];

            temp = temp->nextElement;
            }

        delete[] visited;
        visited = NULL;
        delete[] distance;
        distance = NULL;
        return -1;
        }

}

int main() {
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(2,5);
    g.addEdge(5,6);
    g.addEdge(3,6);
    cout << findMin(g, 1, 6) << endl;
}