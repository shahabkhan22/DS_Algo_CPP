#include <iostream>
#include "Stack.h"
using namespace std;

int* nextGreaterElement(int * arr, int size){

    myStack stack(size);
    int * result = new int[size];

    int next, top;

    for(int i = size - 1; i>= 0; i--){

        next = arr[i];
        top = stack.getTop();

        while(!stack.isEmpty() && top <= next){
            stack.pop();
            top = stack.getTop();
        }

        if(!stack.isEmpty())
            result[i] = stack.getTop();
        else
            result[i] = -1;

        stack.push(next);
    }
    return result;
}

int main(){
    int arr[] = {4,6,3,2,8,1,9,9};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int * res = nextGreaterElement(arr, arr_size);
    std::cout<<endl<<"Array | NextGreater ";
    for(int i = 0; i<arr_size; i++)
        std::cout<<arr[i]<<" | "<<res[i]<<endl;

    return 0;
}