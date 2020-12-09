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

int main(){
    LinkedList list;
    int num = 0;
    for(int i = 1; i< 10; i++){
        num = rand() % 10 + 1;
        list.insertAtTail(num);
        list.printList();
    }
    if(list.search(6))
        std::cout<<"Element Exists in the Linked List";

    return 0;
}
