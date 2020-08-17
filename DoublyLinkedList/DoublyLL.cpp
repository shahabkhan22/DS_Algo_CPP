#include <iostream>
using namespace  std;

class Node{
public:
    int data;
    Node *nextElement;
    Node *prevElement;
    Node(){
        nextElement = nullptr;
        prevElement = nullptr;
    }
};


class DoublyLinkedList{
private:
    Node *head;
public:
    DoublyLinkedList(){
        head = nullptr;
    }

    bool isEmpty(){
        if(head == nullptr)
            return true;
        else
            return false;
    }

    Node * getHead(){
        return head;
    }

    bool printList(){
        if(isEmpty()){
            std::cout<<endl<<"List is Empty"<<endl;
            return false;
        }

        Node * temp = head;
        std::cout<<endl<<"List : ";

        while(temp != nullptr){
            std::cout<<temp -> data << "->";
            temp = temp->nextElement;
        }
        std::cout<<" null "<<endl;
        return true;
    }

    void insertAtHead(int value){
        Node * newNode = new Node();
        newNode->data = value;
        newNode -> prevElement = nullptr;
        newNode -> nextElement = head;
        if(head != nullptr)
            head->prevElement = newNode;

        head = newNode;
        std::cout<< value<<" Inserted at Head"<<endl;
    }

    bool deleteAtHead(int value){
        bool deleted = false;
        if(isEmpty()){
            std::cout<<"List is Empty"<<endl;
            return deleted;
        }

        head = head->nextElement;
        head->prevElement = nullptr;

        return true;
    }

    bool Delete(int value){
        bool deleted = false;
        if(isEmpty()){
            std::cout<<"List is Empty"<<endl;
            return deleted;
        }

        Node * currentNode = head;

        if(currentNode->data == value){
            cout <<value<<" DELETED"<<endl;
            deleted = deleteAtHead(value);
            return deleted;
        }

        while(currentNode != nullptr){
            if(currentNode->data == value){
                currentNode->prevElement->nextElement = currentNode->nextElement;

                if(currentNode->nextElement != nullptr)
                    currentNode->nextElement->prevElement = currentNode->prevElement;

                std::cout<<value<<" DELETED"<<endl;

                deleted = true;
                return deleted;
            }

            currentNode = currentNode->nextElement;
        }

        if(deleted == false)
            std::cout<<value<<" NOT in LIST"<<endl;

        return deleted;
    }
};

int main(){
    DoublyLinkedList dll;
    for(int i =1; i<10; i++){
        dll.insertAtHead(i);
        dll.printList();
    }

    dll.Delete(5);
    dll.printList();

    dll.Delete(2);
    dll.printList();

    dll.Delete(12);
    dll.printList();

    dll.Delete(9);
    dll.printList();

    return 0;
}