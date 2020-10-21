#include <iostream>
#include "BST.h"
using namespace std;


void findk(Node * rootNode, int k, string *result)
{
    if(rootNode == NULL)
        return ;
    if(k == 0)
    {
        *(result) = *(result)+ to_string(rootNode->value) + ",";
    }

    else
    {   //decrement value of k a each step till you reach leaf or when k==0
        findk(rootNode->leftChild, k-1, result);
        findk(rootNode->rightChild, k-1, result);
    }
    
}

string BinarySearchTree::findKNodes(Node *rootNode, int k)
{
    string * result = new string;
    findk(root, k, result);

    return *(result);
}

int main()
{
    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);
    BST.insertBST(12);

    std::cout<<BST.findKNodes(BST.getRoot(), 2)<<endl;

    return 0;
}