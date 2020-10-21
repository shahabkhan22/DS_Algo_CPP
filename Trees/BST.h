#include<iostream>
#include "Node.h"
#include "ArrayList.h"
using namespace std;

class BinarySearchTree{
    Node * root;
public:
    BinarySearchTree(int rootValue){
        root = new Node(rootValue);
    }

    BinarySearchTree(){
        root = NULL;
    }

    Node *getRoot() {
        return root;
    }

    void inOrderPrint(Node *currentNode){
        if (currentNode != NULL){
            inOrderPrint(currentNode->leftChild);
            std::cout<<currentNode->value<<endl;
            inOrderPrint(currentNode -> rightChild);
        }
    }

    void insertBST(int val) {
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
    
    void insertRecursive(int value) {
    if(getRoot() == NULL){
        root = new Node(value);
        return;
    }
    insertRecursiveHelper(this->getRoot(), value);
}

    Node *insertRecursiveHelper(Node * currentNode, int val){
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

    Node * searchBSTHelper(Node * currentNode, int value){
        if(currentNode == NULL)
            return NULL;
        else if(currentNode->value == value)
            return currentNode;
        else if(currentNode->value > value)
            return searchBSTHelper(currentNode->leftChild, value);
        else
            return searchBSTHelper(currentNode->rightChild, value);
        
    }

    Node * searchBST(int value){
        Node *temp = searchBSTHelper(root, value);
        if(temp)
            std::cout<<"Value Found"<<temp->value<<endl;
        else    
            std::cout<<"Value Not Found!"<<endl;
        
        return temp;
    }
    
    bool Delete(Node * currentNode, int value) {

        if (root == NULL) {
            return false;
        }
        Node * parent; //To Store parent of currentNode
        while (currentNode != NULL && (currentNode -> value != value)) {
            parent = currentNode;
            if (currentNode -> value > value)
                currentNode = currentNode -> leftChild;
            else
                currentNode = currentNode -> rightChild;

        }

        if (currentNode == NULL) {
            return false;
        } 
        else if (currentNode -> leftChild == NULL && currentNode -> rightChild == NULL) {
        //1. Node is Leaf Node
        //if that leaf node is the root (a tree with just root)
            if (root -> value == currentNode -> value) {
                delete root;
                root = NULL;
                return true;
            }
            else if (currentNode -> value < parent -> value) {
                delete parent -> leftChild;
                parent -> leftChild = NULL;
                return true;
            } 
            else {
                delete parent -> rightChild;
                parent -> rightChild = NULL;
                return true;
            }
        } 
    else if (currentNode -> rightChild == NULL) {

        if (root -> value == currentNode -> value) {
            delete root;
            root = currentNode -> leftChild;
            return true;
        }    
        else if (currentNode -> value < parent -> value) {

            delete parent -> leftChild;
            parent -> leftChild = currentNode -> leftChild;
            return true;
        } 
    else {
      delete parent -> rightChild;
      parent -> rightChild = currentNode -> leftChild;
      return true;
    }

    }
    else if (currentNode -> leftChild == NULL) {

        if (root -> value == currentNode -> value) {
            delete root;
            root = currentNode -> rightChild;
            return true;
        } 
        else if (currentNode -> value < parent -> value) {
            delete parent -> leftChild;
            parent -> leftChild = currentNode -> rightChild;
            return true;
        } 
        else {
            delete parent -> rightChild;
            parent -> rightChild = currentNode -> rightChild;
            return true;
        }

    } 
    else {
        //Find Least Value Node in right-subtree of current Node
        Node * leastNode = findLeastNode(currentNode -> rightChild);
        //Set CurrentNode's Data to the least value in its right-subtree
        int tmp = leastNode -> value;
        Delete(root, tmp);
        currentNode -> value = tmp;
        //Delete the leafNode which had the least value
        return true;
    }

}

    //Helper function to find least value node in right-subtree of currentNode
    Node * findLeastNode(Node * currentNode) {

  Node * temp = currentNode;
  while (temp -> leftChild != NULL) {
    temp = temp -> leftChild;
  }

  return temp;
}

    bool deleteBST(int value){
    return Delete(root, value);
}

    void preOrderTraversal(Node * currentNode){
        if(currentNode != NULL){
            std::cout<<" "<<currentNode->value;
            preOrderTraversal(currentNode->leftChild);
            preOrderTraversal(currentNode->rightChild);
        }
    }

    void postOrderTraversal(Node * currentNode){
        if(currentNode != NULL){
            postOrderTraversal(currentNode -> leftChild);
            postOrderTraversal(currentNode -> leftChild);
            std::cout<<" "<<currentNode->value;
        }
    }

    void inOrderTraversal(Node * rootNode, ArrayList * result);

    int findMin(Node * rootNode);

    int findKthMax(Node * rootNode, int k, int nodes);

    string findAncestors(Node * rootNode, int k);

    int findHeight(Node * rootNode);

    string findKNodes(Node * rootNode, int k);
};