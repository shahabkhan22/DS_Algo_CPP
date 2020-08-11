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

int main(){
    LinkedList list1, list2;
    for(int i = 1; i <=10; i++){
        list1.insertAtTail(i);
    }
    std::cout<<endl<<"List-1 = ";
    list1.printList();

    for(int i = 3; i <=7; i++){
        list1.insertAtTail(i);
    }
    std::cout<<endl<<"List-2 = ";
    list2.printList();


    LinkedList list3, list4;
    for(int i = 1; i <=10; i++){
        list3.insertAtTail(i);
    }
    std::cout<<endl<<"List-1 = ";
    list3.printList();

    for(int i = 3; i <=7; i++){
        list4.insertAtTail(i);
    }
    std::cout<<endl<<"List-2 = ";
    list4.printList();
    std::cout<<endl<<endl<<endl<<"UNION = ";
    LinkedList().Union(list1, list2);
    std::cout<<endl<<endl<<endl<<"INTERSECTION = ";
    LinkedList().Intersection(list3, list4);

    return 0;

}
