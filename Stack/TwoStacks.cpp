/*
 * Implement Two Stacks using a single Array
 * Functions -
 * void push1(int )
 * void push2(int )
 * void pop1()
 * void pop2()
 */

#include <iostream>
using namespace std;

class twoStacks{
private:
    int size;
    int * arr;
    int top1, top2;

public:
    twoStacks(int n){
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int value){
        if(top1 < top2 - 1)         //check for empty space and then insert
            arr[++top1] = value;
    }

    int pop1(){
        if(top1 >= 0){              //check if element exist and then decrement top and return value
            int val = arr[top1--];
            return val;
        }
        return -1;
    }

    void push2(int value){          //check for empty space and then insert
        if(top1 < top2 -1)
            arr[--top2] = value;
    }

    int pop2(){                     //check if element exist and then increment top and return value
        if(top2 < size){
            int val = arr[top2++];
            return val;
        }
        return -1;
    }
};


int main(){
    twoStacks tS(8);
    tS.push1(1);
    tS.push2(10);
    tS.push1(2);
    tS.push2(9);
    tS.push1(3);
    tS.push2(8);
    tS.push1(4);
    tS.push2(7);
    tS.push1(5);
    tS.push2(6);

    std::cout<<endl<<tS.pop1();
    std::cout<<endl<<tS.pop2();
    std::cout<<endl<<tS.pop1();
    std::cout<<endl<<tS.pop2();
    std::cout<<endl<<tS.pop1();
    std::cout<<endl<<tS.pop2();
    std::cout<<endl<<tS.pop1();
    std::cout<<endl<<tS.pop2();
    return 0;
}