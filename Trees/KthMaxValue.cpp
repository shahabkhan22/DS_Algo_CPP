#include <iostream>
#include "BST.h"
#include "ArrayList.h"
using namespace std;


void BinarySearchTree::inOrderTraversal(Node * rootNode, ArrayList * result)
{
    if(rootNode != NULL)
    {
        inOrderTraversal(rootNode->leftChild, result);
        result->insert(rootNode->value);
        inOrderTraversal(rootNode->rightChild, result);
    }
}

int BinarySearchTree::findKthMax(Node * rootNode, int k, int nodes)
{
    if(k <= 0)
        return -1;
    
    ArrayList *result = new ArrayList(nodes);
    inOrderTraversal(rootNode, result);
    return result->getAt(nodes-k);
}

int main() {
  BinarySearchTree bsT(6);
  bsT.insertBST(3);
  bsT.insertBST(8);
  bsT.insertBST(12);
  bsT.insertBST(10);
  bsT.insertBST(14);
  std::cout <<bsT.findKthMax(bsT.getRoot(), 3, 6)  << endl;
  return 0;
}