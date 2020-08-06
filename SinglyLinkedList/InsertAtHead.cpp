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

int main(){
    LinkedList list;
    for(int i = 1; i< 10; i++){
        list.insertAtHead(i);
        list.printList();
    }

}