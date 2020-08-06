#include<iostream>
using namespace std;
#ifndef DS_ALGO_CPP_LINKEDLIST_H
#define DS_ALGO_CPP_LINKEDLIST_H

#endif //DS_ALGO_CPP_LINKEDLIST_H

class Node{
public:
    int data;
    Node * next;

    Node(){
        next = nullptr;
    }
};

class LinkedList{
private:
    Node * head;
public:
    LinkedList();
    Node *getHead();
    bool isEmpty();
};