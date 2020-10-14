#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *leftChild;
    Node *rightChild;
    Node(){
        value = 0;
        leftChild = NULL;
        rightChild = NULL;
    }

    Node(int val){
        value = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};