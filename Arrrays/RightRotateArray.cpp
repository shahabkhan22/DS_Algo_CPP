#include <iostream>
using namespace std;

void rightRotate(int arr[], int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    cout << endl;
    int last = arr[size -1];
    for(int i = size; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};

    rightRotate(arr, size);

    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    return 0;
}

