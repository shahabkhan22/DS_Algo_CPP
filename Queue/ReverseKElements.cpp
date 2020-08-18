#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

myQueue reverseKElements(myQueue queue, int k){
    if(!queue.isEmpty()){
        myStack stack(k);
        int count = 0;
        while(count < k){
            stack.push(queue.deQueue());
            count++;
        }

        while(!stack.isEmpty())
            queue.enQueue(stack.pop());

        int size = queue.getSize();

        for(int i = 0; i < size -k; i++)
            queue.enQueue(queue.deQueue());
    }

    return queue;
}


int main(){
    myQueue queue(10);
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
    queue.enQueue(6);
    queue.enQueue(7);
    queue.enQueue(8);
    queue.enQueue(9);
    queue.enQueue(10);

    queue = reverseKElements(queue, 5);

    queue.showQueue();
    return 0;
}