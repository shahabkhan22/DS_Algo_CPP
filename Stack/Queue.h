#include <iostream>
using namespace std;

class myQueue{
private:
    int * queueArr;
    int capacity;
    int numElements;
    int front;
    int back;
public:
    myQueue(int size);
    void enQueue(int value);
    int deQueue();
    bool isEmpty();
    int getFront();
    int getSize();
    void showQueue();
};