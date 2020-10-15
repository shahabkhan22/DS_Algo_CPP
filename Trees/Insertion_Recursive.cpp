#include <iostream>
#include "BST.h"
using namespace std;

void BinarySearchTree::insertRecursive(int value) {
    if(getRoot() == NULL){
        root = new Node(value);
        return;
    }
    insertRecursiveHelper(this->getRoot(), value);
}

Node *BinarySearchTree::insertRecursiveHelper(Node * currentNode, int val){
    if(currentNode == NULL){
        return new Node(val);
    }
    else if(currentNode->value > val){
        currentNode->leftChild = insertRecursiveHelper(currentNode->leftChild, val);
    }
    else{
        currentNode->rightChild = insertRecursiveHelper(currentNode->rightChild, val);
    }

    return currentNode;
}

int main(){
    BinarySearchTree BST(13);
    BST.insertRecursive(4);
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