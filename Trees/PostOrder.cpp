#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BinarySearchTree BST(6);
    BST.insertBST(4);
    BST.insertBST(9);
    BST.insertBST(5);
    BST.insertBST(2);
    BST.insertBST(8);
    BST.insertBST(12);

    cout << "InOrder Print" << endl;
    BST.inOrderPrint(BST.getRoot());

    cout << "PreOrder Print" << endl;
    BST.postOrderTraversal(BST.getRoot());

}