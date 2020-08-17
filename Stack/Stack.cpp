#include <iostream>
#include <cassert>
#include "Stack.h"
using namespace std;



myStack::myStack(int size){
    capacity = size;
    stackArr = new int[size];
    assert(stackArr!= NULL);
    numElements = 0;
}

bool myStack::isEmpty() {
    return (numElements == 0);
}

int myStack::getTop(){
    return (numElements == 0? -1: stackArr[numElements -1]);
}

bool myStack::push(int value) {
    if (numElements < capacity){
        stackArr[numElements] = value;
        numElements++;
        return true;
    }
    else{
        std::cout<<endl<<"Stack FULL"<<endl;
        return false;
    }
}

int myStack::pop(){
    if (numElements == 0){
        std::cout<<endl<<"Stack EMPTY"<<endl;
        return -1;
    }
    else{
        numElements--;
        return stackArr[numElements];
    }
}

int myStack::getSize(){
    return numElements;
}

void myStack::showStack() {
    int i = 0;
    while (i < numElements){
        std::cout<<"\t"<<stackArr[numElements -1 -i];
        i++;
    }
    std::cout<<endl;
}


int main(){
    myStack s(10);
    std::cout<<endl<<"Stack Top:  "<<s.getTop();
    s.push(10);
    s.push(12);
    s.push(456);
    s.push(45);
    s.push(76);
    s.push(85);
    s.push(654);
    s.push(987);
    s.push(31);
    s.push(65);

    std::cout<<endl<<"Stack: ";
    s.showStack();
    std::cout << "\ns.top(): " << s.getTop();
    std::cout << "\ns.pop(): " << s.pop() << endl;
    std::cout << "\ns.pop(): " << s.pop() << endl;
    std::cout << "\ns.pop(): " << s.pop() << endl;
    std::cout << "\ns.pop(): " << s.pop() << endl;
    s.push(23);
    s.push(57);
    s.push(17);
    s.push(29);
    s.push(6);
    s.push(7);
    s.push(12);
    s.push(19);
    std::cout << "\nThe stack is: ";
    s.showStack();
    std::cout << "\ns.pop(): " << s.pop() << endl;
    std::cout << "s.pop(): " << s.pop() << endl;
    std::cout << "The stack size is: " << s.getSize() << endl;
    return 0;
}