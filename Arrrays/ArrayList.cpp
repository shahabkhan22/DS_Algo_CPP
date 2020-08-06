#include <iostream>
using namespace std;

class ArrayList{
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

void resize(){
    int *tempArr = new int[capacity*2];
    capacity *= 2;

    for(int i=0; i<num_elements; i++){
        tempArr[i] = arr[i];
    }

    delete []arr;
    arr = tempArr;
}

int length(){
    return num_elements;
}

void print(){
    for(int i=0; i<num_elements; i++)
        std :: cout << arr[i] << " ";
    cout << endl;
}
};


/*
int main(){
    ArrayList arr(1);
    std :: cout << "Arr Length : " << arr.length() << endl;
    arr.insert(1);
    arr.insert(654);
    arr.insert(54);
    arr.insert(89);
    arr.insert(34);
    arr.insert(61);
    arr.insert(3);
    arr.insert(97);
    arr.insert(6);
    std :: cout << "Arr Length : " << arr.length() << endl;
    std :: cout << "Array : ";
    arr.print();
    std :: cout << "Element at Index 5 : " <<arr.getAt(4) << endl;
}
*/