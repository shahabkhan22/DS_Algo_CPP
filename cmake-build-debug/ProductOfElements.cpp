#include <iostream>
using namespace std;

int *findProduct_Slower(int arr[], int size){
    int *product = new int[size];

    for(int i = 0; i < size; i++){
        int pro = 1;
        for(int j = 0; j< size; j++){
            if(i == j)
                continue;
            else{
                pro *= arr[j];
            }
            product[i] = pro;
        }
    }
    return product;
}

int *findProduct_Faster(int arr[], int size){
    int n = size;
    int temp = 1;
    int *product = new int[size];

    for(int i =0; i < n; i++){
        product[i] = temp;
        temp *= arr[i];
    }

    temp = 1;

    for(int i = n-1; i >= 0; i++){
        product[i] *= temp;
        temp *= arr[i];
    }

    return product;
}

/*
int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout<<"Find Product Slower | Time Complexity = O(n^2)"<<endl;
    int *arrs = findProduct_Slower(arr, size);

    for(int i = 0; i < size; i++)
        std::cout<< arrs[i] << " ";

    std::cout<<endl<<"Find Product Slower | Time Complexity = O(n)"<<endl;
    int *arrf = findProduct_Faster(arr, size);

    for(int i = 0; i < size; i++)
        std::cout<< arrf[i] << " ";

    return 0;
}
*/
