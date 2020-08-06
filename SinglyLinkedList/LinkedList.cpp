#include "LinkedList.h"

void LinkedList::insertAtHead(int value){
    Node *newNode = new Node();
    newNode -> data = value;
    newNode -> nextElement = head;

}
