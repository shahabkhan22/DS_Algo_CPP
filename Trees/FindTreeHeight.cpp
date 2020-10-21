#include <iostream>
#include "BST.h"
using namespace std;

int BinarySearchTree::findHeight(Node * rootNode)
{
    if(rootNode == NULL)
        return -1;
    else
    {
        int leftHeight = findHeight(rootNode->leftChild);
        int rightHeight = findHeight(rootNode->rightChild);

        if(leftHeight > rightHeight)
            return leftHeight+1;
        else
            return rightHeight+1;
        
    }

    return 0;
    
}

int main(){

BinarySearchTree BST(6);
BST.insertBST(4);
BST.insertBST(9);
BST.insertBST(5);
BST.insertBST(2);
BST.insertBST(8);
BST.insertBST(12);
std::cout<<BST.findHeight(BST.getRoot())<<endl;

return 0;
}