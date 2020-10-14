#include<iostream>
#include "Node.h"
using namespace std;

class BinaySearchTree{
    Node * root;
public:
    BinaySearchTree(int rootValue){
        root = new Node(rootValue);
    }

    BinaySearchTree(){
        root = NULL;
    }

    Node *getRoot() {
        return root;
    }

    void insertBST(int val);

    void inOrderPrint(Node *currentNode){
        if (currentNode != NULL){
            inOrderPrint(currentNode->leftChild);
            std::cout<<currentNode->value<<endl;
            inOrderPrint(currentNode -> rightChild);
        }
    }
};