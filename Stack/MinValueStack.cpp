#include <iostream>
#include "Stack.h"
using namespace std;

class newStack{
    myStack *mainStack;
    myStack *minStack;
public:
    newStack(int size){
        mainStack = new myStack(size);
        minStack = new myStack(size);
    }

    int pop(){
        minStack->pop();
        return mainStack->pop();
    }

    void push(int value){
        mainStack->push(value);

        if(value > minStack->getTop() && !minStack->isEmpty())
            minStack->push(minStack->getTop());
        else
            minStack->push(value);
    }

    int min(){
        return minStack->getTop();
    }
};