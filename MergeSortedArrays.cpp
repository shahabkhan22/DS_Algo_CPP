#include <iostream>
using namespace std;

int * mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size)
{
    int * arr3 = new int[arr1Size + arr2Size]; // creating new array
    // Write your code here
    int i = 0, j = 0, k = 0;

    while(i < arr1Size && j < arr2Size){
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < arr1Size)
        arr3[k++] = arr1[i++];

    while (j < arr2Size)
        arr3[k++] = arr1[j++];

    return arr3; // returning array
}

/*
int main(){
    int arr1[] = {-3, 0, 1, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {-9, -1, 2, 3, 18};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *arr3 = mergeArrays(arr1, arr2, size1, size2);
    for(int i = 0; i < size1+size2; i++)
        std::cout << arr3[i] << " ";
    return 0;
}
*/