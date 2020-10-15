#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BinarySearchTree BST(13);

    BST.insertBST(4);
    BST.insertBST(7);
    BST.insertBST(16);
    BST.insertBST(19);
    BST.insertBST(3);
    BST.insertBST(1);
    BST.insertBST(9);
    BST.insertBST(2);
    BST.insertBST(5);
    BST.insertBST(15);

    std::cout<<"InOrder Traversal:  "<<endl;
    BST.inOrderPrint(BST.getRoot());

    std::cout<<"Deleting 4"<<endl;
    BST.deleteBST(4);

    std::cout<<"BST After Deleting 4:  "<<endl;
    BST.inOrderPrint(BST.getRoot());

    return 0;
}