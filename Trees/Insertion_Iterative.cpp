#include <iostream>
#include "BST.h"
using namespace std;

void BinaySearchTree::insertBST(int val) {
    if (getRoot() == NULL){
        root = new Node(val);
        return;
    }

    //starting from root
    Node *currentNode = root;
    Node *parent;

    while(currentNode){
        parent = currentNode;   //update the parent
        if (val < currentNode->value){  //iterate to left subtree
            currentNode = currentNode->leftChild;
        }
        else{
            currentNode = currentNode->rightChild;
        }
    }

    if (val < parent->value){
        parent->leftChild = new Node(val);
    }
    else{
        parent->rightChild = new Node(val);
    }
}

int main(){
    BinaySearchTree BST(13);
    BST.insertBST(4);
    BST.insertBST(7);
    BST.insertBST(16);
    BST.insertBST(19);
    BST.insertBST(3);
    BST.insertBST(1);
    BST.insertBST(9);
    BST.insertBST(2);

    std::cout<<"InOrderTraversal: "<<endl;
    BST.inOrderPrint(BST.getRoot());
    return 0;
}