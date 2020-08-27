#include <iostream>
#include "Graph.h"
using namespace std;
/*
bool checkPath(Graph g, int source, int destination){
    if(source == destination)
        return true;

    //Bool array to hold history of visite nodes
    //Make node visited whenever it is pushed in stack
    bool * visited = new bool[g.getVertices()];

    //create stack
    myStack stack(g.getVertices());

    stack.push(source); //push the source as it is first node
    visited[source] = true;

    //Traverse while stack is not empty
    Node * temp;
    int current_node;
    while(!stack.isEmpty()){
        current_node = stack.pop(); //pop a vertex from stack

        temp = (g.getArray())[current_node].getHead(); //gets array(Adjacency Linked list) associated to the current_node
        while(temp != NULL){
            if(!visited[temp->data]){
                //check if the current node is the destination, return true
                if(temp->data == destination)
                    return true;
                //as current node is not destination, push it into the stack
                //mark the current node value as visited
                stack.push(temp->data);
                visited[temp->data] = true;
            }
            temp = temp->nextElement;
        }

        delete[] visited;
        visited = NULL;
        return false;
    }
}
*/
bool checkPath(Graph g, int source, int destination) {
    if (source == destination){
        return true;
    }

    //Bool Array to hold the history of visited nodes
    //Make a node visited whenever you push it into stack
    bool* visited = new bool[g.getVertices()];

    //Create Stack
    myStack stack(g.getVertices());

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
        //Before pushing into stack, check if it's the destination.
        temp = (g.getArray())[current_node].getHead();

        while (temp != NULL) {

            if (!visited[temp->data]) {

                if (temp->data == destination) {
                    return true;
                }

                stack.push(temp->data);
                visited[temp->data] = true;

            }

            temp = temp->nextElement;
        }

    } //end of while
    delete[] visited;
    visited = NULL;
    return false;
}
int main(){
    Graph g1(9);
    g1.addEdge(0,2);
    g1.addEdge(0,5);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(5,3);
    g1.addEdge(5,6);
    g1.addEdge(3,6);
    g1.addEdge(6,7);
    g1.addEdge(6,8);
    g1.addEdge(6,4);
    g1.addEdge(7,8);
    Graph g2(4);
    g2.addEdge(0,1);
    g2.addEdge(1,2);
    g2.addEdge(1,3);
    g2.addEdge(2,3);

    cout<<endl;
    bool path1 = checkPath(g1, 0, 7);
    bool path2 = checkPath(g2, 3, 0);
    cout << "Path1(0->7) : " <<path1<< endl;
    cout << "Path2(3->0) : " <<path2<< endl;
}