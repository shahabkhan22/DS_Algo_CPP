#include <iostream>

class ArrayList(){
    int *arr;
    int num_elements;
    int capacity;


public:
    ArrayList(int size){
        arr = new int[size];
        num_elements = 0;
        capacity = size;
    }

    void insert(int val){
        if(num_elements < capacity){
            arr[num_elements] = val;
            num_elements++;
        }
        else{
            resize();
            arr[num_elements] = val;
            num_elements++;
        }
    }

    int getAt(int index){
        return arr[index];
    }

    
};