#include <iostream>
#include "BST.h"
using namespace std;

bool recur(Node *rootNode, int k, string *result)
{
    if(rootNode == NULL)
        return false;
    else if(rootNode ->value == k)
        return true;
    else
    {
        if(recur(rootNode->leftChild, k, result) || (rootNode->rightChild, k, result))
        {
            *(result) = *(result) + to_string(rootNode->value) + ",";
            return true;
        }
    }

    return false;
    
}

string BinarySearchTree::findAncestors(Node * rootNode, int k)
{
    string * result = new string;
    recur(rootNode, k, result);

    return *(result);
}

int main()
{
    BinarySearchTree BST(6);
    BST.insertBST(1);
    BST.insertBST(133);
    BST.insertBST(12);

    std::cout<<BST.findAncestors(BST.getRoot(), 12)<<endl;
    return 0;
}


/*=====Iterative Approach================


string findAncestors(Node *rootNode, int k) {

  if(rootNode==NULL)
    return "";
  
  string ancestors = ""; 
  Node* currentNode = rootNode;
  
  while(currentNode!=NULL){
    if(k>currentNode->value){
      ancestors+=to_string(currentNode->value) + ",";   
      currentNode = currentNode->rightChild;
    }
    else if( k < currentNode->value){
      ancestors+=to_string(currentNode->value) + ",";   
      currentNode = currentNode->leftChild;
    }
    else  // when k == currentNode.value
      return ancestors;
  }
  return "";
}
*/