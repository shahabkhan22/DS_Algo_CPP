#include <iostream>
#include "BST.h"
using namespace std;

static int counter = 0;

Node * findKthMaxRecursive(Node * root, int k)
{
    if(root == nullptr || counter >= k)
        return nullptr;
    
    Node * node = findKthMaxRecursive(root->rightChild, k); //recursiverly reaches right-most which is highest value

    if(counter != k)
    {
        counter++; // increment counter if kth element is not found
        node = root;
    }

    if(counter == k) //as k'th position reached
        return node;
    else
        return findKthMaxRecursive(root->leftChild, k);
}


int findKthMax(Node * root, int k)
{
    Node * node = findKthMaxRecursive(root, k);
    if(node != nullptr)
        return node->value;
    return -1;
}

int main()
{
    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);

    std::cout<<findKthMax(BST.getRoot(), 4);
    return 0;
}