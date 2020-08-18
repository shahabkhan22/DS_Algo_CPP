#include <iostream>
#include "Stack.h"
using namespace std;

class newQueue{
private:
    myStack * mainStack;
    myStack * tempStack;
public:
    newQueue(int size){
        mainStack = new myStack(size);
        tempStack = new myStack(size);
    }

    void enQueue(int value){
        //Traverse elements from mainStack to tempStack
        //Push given value to mainStack
        //Traverse back the elements from tempStack to mainStack
        while(!mainStack->isEmpty())
            tempStack->push(mainStack->pop());

        mainStack->push(value);

        while(!tempStack->isEmpty())
            mainStack->push(tempStack->pop());
    }

    int deQueue(){
        if(mainStack->isEmpty())
            return -1;
        else
            return mainStack->pop();
    }
};

int main(){
    newQueue queue(5);

    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);

    std::cout<<endl<<queue.deQueue();
    std::cout<<endl<<queue.deQueue();
    std::cout<<endl<<queue.deQueue();
    std::cout<<endl<<queue.deQueue();
    std::cout<<endl<<queue.deQueue();

    return 0;
}
