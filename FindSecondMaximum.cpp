#include <iostream>
using namespace std;

int findSecondMaximum_twiceArrayTraversal(int arr[], int size){

    int max = INT64_MIN;
    int secondMax = INT64_MIN;

    for(int i = 0; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    for(int i = 0; i < size; i++){
        if(arr[i] > secondMax && arr[i] < max)
            secondMax = arr[i];
    }

    return secondMax;
}

int findSecondMax_onceArrayTraversal(int arr[], int size){
    int max = INT64_MIN;
    int duplicates;
    int secondMax = INT64_MIN;

    for(int i = 1; i < size; i++){
        if(arr[0] == arr[i])
            duplicates++;
    }
    if (duplicates == size-1){
    std::cout << "Array should have at least 2 uniques elements" << endl;
    return secondMax;
    }

    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] != max)
            secondMax = arr[i];
    }
    return secondMax;
}
/*
int main(){
    int size = 6;
    int arr[size] = {2,3,3,1,3,3};

    int secmax = findSecondMaximum_twiceArrayTraversal(arr, size);
    std::cout<<"By Twice Traversal: "<<secmax<<endl;

    secmax = findSecondMax_onceArrayTraversal(arr, size);
    std::cout<<"By Single Traversal: "<<secmax<<endl;

    return 0;
}
*/