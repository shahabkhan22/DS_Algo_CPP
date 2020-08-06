#include <iostream>
using namespace std;

void maxMin(int arr[], int size){
    int *result = new int[size];
    //Assumption - Array is sorted in Ascending Order
    int pointSmall = 0;         //points to smallest
    int pointLarge = size -1;   //points to largest

    bool switchPointer = true;

    for(int i =0; i < size; i++){
        if(switchPointer)
            result[i] = arr[pointLarge--];
        else
            result [i] = arr[pointSmall++];

        switchPointer = !switchPointer;
    }

    for(int i = 0; i < size; i++)
        arr[i] = result[i];

    delete[] result;
}


int main(){
    int size = 7;
    int arr[size] = {1,2,3,4,5,6,7};

    std::cout<<"Array after Swapping : " << endl;
    maxMin(arr, size);
    for(int i = 0; i< size; i++)
        std::cout << arr[i] << " ";

    return 0;
}