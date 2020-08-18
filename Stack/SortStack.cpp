#include <iostream>
#include "Stack.h"
using namespace std;

myStack sortStack_tempStack(myStack stack, int size){
    myStack tempStack(size);

    while(!stack.isEmpty()){
        int value = stack.pop();

        if(value >- tempStack.getTop())
            tempStack.push(value);
        else{
            while(!tempStack.isEmpty())
                stack.push(tempStack.pop());
            tempStack.push(value);
        }
    }

    while(!tempStack.isEmpty())
        stack.push(tempStack.pop());

    return stack;
}

void sortStack_Recursive(myStack * stack){
    if(!stack->isEmpty()){
        int value = stack->pop();
        sortStack_Recursive(stack);
        insert(stack, value);
    }
}

void insert(myStack * stack, int value){
    if(stack->isEmpty() || value < stack->getTop())
        stack->push(value);
    else{
        int temp = stack->pop();
        insert(stack, value);
        stack->push(temp);
    }
}

int main(){
    myStack * stack = new myStack(7);
    stack->push(2);
    stack->push(97);
    stack->push(4);
    stack->push(43);
    stack->push(12);
    stack->push(60);
    stack->push(23);
    stack = (sortStack_tempStack(stack, 7));

}