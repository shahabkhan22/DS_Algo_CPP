#include <iostream>
#include <cassert>
#include "Queue.h"
using namespace std;

myQueue::myQueue(int size) {
    capacity = size;
    queueArr = new int[size];
    assert(queueArr != NULL);
    numElements = 0;
    front = 0;
    back = -1;
}

bool myQueue::isEmpty() {
    return (numElements == 0);
}

int myQueue::getFront() {
    if (isEmpty()){
        std::cout<<endl<<"Queue Empty"<<endl;
    }
    else
        return queueArr[front];
}

int myQueue::getSize() {
    return numElements;
}

void myQueue::enQueue(int value) {
    if(numElements == capacity){
        std::cout<<endl<<"Queue FULL"<<endl;
        return;
    }

    if(back == capacity -1)
        back = -1;

    queueArr[++back] = value;
    numElements++;
}

int myQueue::deQueue() {
    if(isEmpty()){
        std::cout<<endl<<"Queue EMPTY";
        return -1;
    }

    int temp = queueArr[front++];
    if(front == capacity)
        front = 0;
    numElements--;
    return temp;
}

void myQueue::showQueue() {
    int i = front;
    int count = 0;
    while(count != numElements){
        std::cout<<"  "<<queueArr[i%capacity];
        i++;
        count ++;
    }
    std::cout<<endl;
}

/*
int main(){
    myQueue queue(5);
    queue.enQueue(2);
    queue.enQueue(4);
    queue.enQueue(6);
    queue.enQueue(8);
    queue.enQueue(10);
    queue.showQueue();
    std::cout << "Adding 6th element to a queue with capacity equal to 5: " << endl;
    queue.enQueue(12);

    queue.showQueue();
    queue.deQueue();
    queue.deQueue();
    queue.showQueue();
    std::cout << "The size of queue is: " << queue.getSize() << endl;
    queue.enQueue(14);
    queue.enQueue(16);
    queue.enQueue(25);
    std::cout << "The size of queue is: " << queue.getSize() << endl;

    return 0;
}
*/