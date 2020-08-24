#include <iostream>
#include <cassert>
using namespace std;
#ifndef DS_ALGO_CPP_GRAPH_H
#define DS_ALGO_CPP_GRAPH_H

#endif //DS_ALGO_CPP_GRAPH_H

//----------Linked List-----------------
class Node{
public:
    int data;
    Node * nextElement;

    Node(){
        nextElement = nullptr;
    }
};

class LinkedList{
private:
    Node * head;
public:
    LinkedList();
    Node *getHead();
    bool isEmpty();
    bool printList();
    void insertAtHead(int value);
    void insertAtTail(int value);
    bool search(int value);
    bool deleteAtHead();
    bool deleteAtValue(int value);
    int length();
    void reverse();
    void insertLoop();
    bool detectLoop();
    int findMidddleElement();
    void removeDuplicates();
    void Union(LinkedList list1, LinkedList list2);
    void Intersection(LinkedList list1, LinkedList list2);
};

LinkedList::LinkedList(){
    head = nullptr;
}

Node *LinkedList::getHead(){
    return head;
}

bool LinkedList::isEmpty(){
    if(head == nullptr)
        return true;
    else
        return false;
}

bool LinkedList::printList(){
    if(isEmpty()){
        std::cout << endl<<"List is Empty";
        return false;
    }
    Node *temp = head;
    std::cout<<endl<<"List : ";

    while(temp != nullptr){
        std::cout<< temp -> data <<"->";
        temp = temp ->nextElement;
    }

    cout << "null" << endl;
    return true;
}

void LinkedList::insertAtHead(int value) {
    Node *newNode = new Node();
    newNode -> data = value;
    newNode -> nextElement = head;
    head = newNode;
    cout << value <<" Inserted";
}

void LinkedList::insertAtTail(int value) {
    if(isEmpty())
        insertAtHead(value);
    else{
        Node * newNode = new Node();
        Node *last = head;

        while(last ->nextElement != nullptr)
            last = last->nextElement;

        newNode->data = value;
        std::cout<<value<<" Inserted";
        newNode->nextElement = nullptr;
        last->nextElement = newNode;

    }
}

bool LinkedList::search(int value) {
    Node * temp = head;

    while(temp != nullptr){
        if(temp->data == value)
            return true;

        temp = temp ->nextElement;
    }
    return false;
}

bool LinkedList::deleteAtHead(){
    if (isEmpty()){
        std::cout<<"List is Empty" << endl;
        return false;
    }
    Node *currentNode = head;
    head = head->nextElement;

    delete currentNode;
    return true;
}

bool LinkedList::deleteAtValue(int value) {
    if(isEmpty()){
        std::cout<<"List is Empty"<<endl;
        return false;
    }
    Node *currentNode = head;
    Node *previousNode = NULL;

    if(currentNode != NULL && currentNode->data == value){
        head = currentNode->nextElement;
        delete currentNode;
    }

    while(currentNode != NULL && currentNode->data != value){
        previousNode = currentNode;
        currentNode = currentNode->nextElement;
    }

    if(currentNode == NULL)
        std::cout<<"Element not in the Linked List"<<endl;

    previousNode->nextElement = currentNode->nextElement;
    delete currentNode;
    std::cout<<value <<"Element not in the Linked List"<<endl;
}

int LinkedList::length() {
    int count = 0;

    Node * currentNode = head;
    if(isEmpty()){
        std::cout<<"List is Empty!"<<endl;
        return 0;
    }

    while(currentNode != NULL){
        count++;
        currentNode = currentNode->nextElement;
    }

    return count;
}

void LinkedList::reverse() {

    Node * previousNode = nullptr;
    Node * currentNode = head;
    Node *nextNode = nullptr;

    while(currentNode != nullptr){
        nextNode = currentNode->nextElement;
        currentNode->nextElement = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    head = previousNode;

}

void LinkedList::insertLoop() {
    Node *temp = head;

    while(temp->nextElement != nullptr)
        temp = temp->nextElement;

    temp->nextElement = head;
}

bool LinkedList::detectLoop() {
    Node * slow = head;
    Node * fast = head;

    while(slow && fast && fast->nextElement){
        slow = slow->nextElement;
        fast = fast->nextElement->nextElement;

        if(slow == fast)
            return true;
    }

    return false;
}

int LinkedList::findMidddleElement() {
    if(isEmpty())
        return 0;

    Node * currentNode = head;

    if(currentNode->nextElement == nullptr)
        return currentNode->data;

    Node * middleNode = currentNode;
    currentNode = currentNode->nextElement->nextElement;

    while(currentNode != nullptr){
        middleNode = middleNode->nextElement;
        currentNode = currentNode->nextElement;

        if(currentNode != nullptr)
            currentNode = currentNode->nextElement;
    }
    if(middleNode != nullptr)
        return middleNode->data;

    return 0;
}

void LinkedList::removeDuplicates() {
    Node * start, * startNext, * duplicate;
    start = head;

    while(start != nullptr && start->nextElement != nullptr){
        startNext = start;

        while(startNext->nextElement != nullptr){
            if(start->data == startNext->nextElement->data){
                duplicate = startNext->nextElement;
                startNext->nextElement = startNext->nextElement->nextElement;
                delete (duplicate);
            }
            else
                startNext = startNext->nextElement;
        }
        start = start->nextElement;
    }

}

void LinkedList::Union(LinkedList list1, LinkedList list2) {
    if(list1.isEmpty())
        list2.printList();
    else if(list2.isEmpty())
        list1.printList();

    Node * start = list1.head;

    while(start->nextElement != nullptr)
        start = start->nextElement;

    start->nextElement = list2.head;
    list1.removeDuplicates();
    list1.printList();
}

void LinkedList::Intersection(LinkedList list1, LinkedList list2) {
    LinkedList list3;
    Node *t1 = list1.head, *t2 = list2.head;

    while(t1 != nullptr){
        while(t2 != nullptr){
            if(t1->data == t2->data)
                list3.insertAtHead(t1->data);
            t2 = t2->nextElement;
        }
        t2 = list2.head;
        t1 = t1->nextElement;
    }
    list3.removeDuplicates();
    list3.printList();
}

//-------------Queue----------------------------

class myQueue{
private:
    int * queueArr;
    int capacity;
    int numElements;
    int front;
    int back;
public:
    myQueue(int size);
    void enQueue(int value);
    int deQueue();
    bool isEmpty();
    int getFront();
    int getSize();
    void showQueue();
};

myQueue::myQueue(int size) {
    capacity = size;
    queueArr = new int[size];
    assert(queueArr != NULL);
    numElements = 0;
    front = 0;
    back = -1;
}

bool myQueue::isEmpty() {
    return (numElements == 0);
}

int myQueue::getFront() {
    if (isEmpty()){
        std::cout<<endl<<"Queue Empty"<<endl;
    }
    else
        return queueArr[front];
}

int myQueue::getSize() {
    return numElements;
}

void myQueue::enQueue(int value) {
    if(numElements == capacity){
        std::cout<<endl<<"Queue FULL"<<endl;
        return;
    }

    if(back == capacity -1)
        back = -1;

    queueArr[++back] = value;
    numElements++;
}

int myQueue::deQueue() {
    if(isEmpty()){
        std::cout<<endl<<"Queue EMPTY";
        return -1;
    }

    int temp = queueArr[front++];
    if(front == capacity)
        front = 0;
    numElements--;
    return temp;
}

void myQueue::showQueue() {
    int i = front;
    int count = 0;
    while(count != numElements){
        std::cout<<"  "<<queueArr[i%capacity];
        i++;
        count ++;
    }
    std::cout<<endl;
}

//--------------Stack---------------------

class myStack {
private:
    int * stackArr;
    int capacity;
    int numElements;
public:
    myStack(int size);
    bool isEmpty();
    int getTop();
    bool push(int value);
    int pop();
    int getSize();
    void showStack();
};


myStack::myStack(int size){
    capacity = size;
    stackArr = new int[size];
    assert(stackArr!= NULL);
    numElements = 0;
}

bool myStack::isEmpty() {
    return (numElements == 0);
}

int myStack::getTop(){
    return (numElements == 0? -1: stackArr[numElements -1]);
}

bool myStack::push(int value) {
    if (numElements < capacity){
        stackArr[numElements] = value;
        numElements++;
        return true;
    }
    else{
        std::cout<<endl<<"Stack FULL"<<endl;
        return false;
    }
}

int myStack::pop(){
    if (numElements == 0){
        std::cout<<endl<<"Stack EMPTY"<<endl;
        return -1;
    }
    else{
        numElements--;
        return stackArr[numElements];
    }
}

int myStack::getSize(){
    return numElements;
}

void myStack::showStack() {
    int i = 0;
    while (i < numElements){
        std::cout<<"\t"<<stackArr[numElements -1 -i];
        i++;
    }
    std::cout<<endl;
}


//--------------------Graph-----------------------

class Graph{
private:
    int vertices;
    LinkedList * array;
public:
    Graph(int v);
    void addEdge(int source, int destination);
    void printGraph();
    int getVertices();
    LinkedList * getArray();
};

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

int Graph::getVertices() {
    return vertices;
}
LinkedList* Graph::getArray() {
    return array;
}