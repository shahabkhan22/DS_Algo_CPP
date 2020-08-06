#include <iostream>
using namespace std;

int *findSum_bruteForce(int arr[], int value, int size){
    int *result = new int[2];

    for(int i = 0; i< size; i++){
        for (int j = i+1; j < size; j++){
            if(arr[i] + arr[j] == value){
                result[0] = arr[i];
                result[1] = arr[j];
                return result;
            }
        }
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1; //index of smaller element
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void sort(int arr[], int low, int high){ //using quicksort
    if(low < high){
        int pi = partition(arr, low, high);
        sort(arr, low, pi-1);
        sort(arr, pi+1, high);
    }
}


int *findSum_SortingArray(int arr[], int value, int size){

    sort(arr, 0, size-1); //sort the array first in ascending order

    int pointer1 = 0;
    int pointer2 = size - 1;
    int *result = new int[2];
    int sum = 0;

    while(pointer1 != pointer2){
        sum = arr[pointer1] + arr[pointer2];
        if (sum < value)
            pointer1++;
        else if(sum > value)
            pointer2++;
        else{
            result[0] = arr[pointer1];
            result[1] = arr[pointer2];
            return result;
        }
    }
    return arr;
}


int main(){
    int size = 5, value = 18;
    int arr[size] = {16,6,12,2,5};

    if(size > 0){
        std::cout<<"Using Brute Force" <<"Time Complexity = O(n^2) "<<endl;
        int *arr2 = findSum_bruteForce(arr, value, size);
        int num1 = arr2[0];
        int num2 = arr2[1];

        if(num1 + num2 != value)
            std::cout << "Not Found" << endl;
        else{
            std::cout << "Num1 = " << num1 << endl;
            std::cout << "Num2 = " << num2 << endl;
            std::cout << "Sum = " << num1 + num2 << endl;
        }
    }
    if(size > 0){
        std::cout<<"Using Sorting Array First" << "Time Complexity = O(nlogn)"<<endl;
        int *arr2 = findSum_SortingArray(arr, value, size);
        int num1 = arr2[0];
        int num2 = arr2[1];

        if(num1 + num2 != value)
            std::cout << "Not Found" << endl;
        else{
            std::cout << "Num1 = " << num1 << endl;
            std::cout << "Num2 = " << num2 << endl;
            std::cout << "Sum = " << num1 + num2 << endl;
        }
    }
    else
        std::cout << "Input Array is Empty" <<endl;


}
