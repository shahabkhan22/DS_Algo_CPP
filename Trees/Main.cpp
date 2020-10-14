#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BinaySearchTree BST(13);
    std::cout<<"Root value of BST: "<<BST.getRoot()->value<<endl;
    return 0;
}