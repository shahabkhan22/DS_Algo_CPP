#include<iostream>
using namespace std;

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
        std::cout << "List is Empty";
        return false;
    }
    Node *temp = head;
    std::cout<<"List : ";

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

int main(){
    LinkedList list;

    for(int i = 1; i < 10; i++){
        list.insertAtTail(i);
    }

    list.printList();
    std::cout<<"List After Reversing: "<<endl;
    list.reverse();
    list.printList();

}