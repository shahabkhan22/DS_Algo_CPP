#include <iostream>
#include "BST.h"
using namespace std;

int BinarySearchTree::findMin(Node * rootNode)
{
    if (rootNode == NULL)
        return -1;
    else if(rootNode->leftChild == NULL)
        return rootNode->value;
    else
        return findMin(rootNode->leftChild);
       

    return rootNode->value;
}

int main() {
  BinarySearchTree bsT(6);
  bsT.insertBST(3);
  bsT.insertBST(8);
  bsT.insertBST(12);
  bsT.insertBST(10);
  bsT.insertBST(14);
  std::cout << bsT.findMin(bsT.getRoot()) << endl;
  return 0;
}