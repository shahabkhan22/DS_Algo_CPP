#include <iostream>
#include "Graph.h"
using namespace std;

int performDFS(Graph g, int source) {

    int num_of_vertices = g.getVertices();
    int vertices_reached = 0; //To store how many vertices reached starting from source
    //Bool Array to hold the history of visited nodes
    //Make a node visited whenever you push it into stack
    bool* visited = new bool[num_of_vertices];

    //Create Stack(Implemented in previous lesson) for Depth First Traversal and Push source in it
    myStack stack(num_of_vertices);

    stack.push(source);
    visited[source] = true;

    //Traverse while stack is not empty
    int current_node;
    Node*temp;
    while (!stack.isEmpty()) {

        //Pop a vertex/node from stack
        current_node = stack.pop();

        //Get adjacent vertices to the current_node from the array,
        //and if only push unvisited adjacent vertices into stack
        temp = (g.getArray())[current_node].getHead();

        while (temp != NULL) {

            if (!visited[temp->data]) {
                stack.push(temp->data);
                visited[temp->data] = true;
                vertices_reached++;
            }

            temp = temp->nextElement;
        }

    } //end of while
    delete[] visited;
    visited = NULL;
    return vertices_reached + 1; //+1 to include the source itself.
}
int findMotherVertex(Graph g) {

    //Traverse the Graph Array and perform DFS operation on each vertex
    //The vertex whose DFS Traversal results is equal to the total number
    //of vertices in graph is a mother vertex
    int num_of_vertices_reached = 0;

    for (int i = 0; i < g.getVertices(); i++) {

        num_of_vertices_reached = performDFS(g, i);

        if (num_of_vertices_reached == g.getVertices()){
            return i;
        }

    }
    return - 1;
}

//Performs DFS Traversal on graph starting from source
//Returns total number of vertices which can be reached from source

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,0);
    g.addEdge(3,1);
    int ret =  findMotherVertex(g);
    std::cout<<endl<<"Mother Node: "<<ret<<endl;
    g.printGraph();
}