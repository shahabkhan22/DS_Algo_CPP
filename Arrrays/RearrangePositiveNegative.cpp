#include <iostream>
using namespace std;

void reArrange_UsingNewArray(int arr[], int size) {
    int *newArr = new int[size];
    int newArr_index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            newArr[newArr_index++] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            newArr[newArr_index++] = arr[i];
    }

    for(int j = 0; j < newArr_index; j++)
        arr[j] = newArr[j];

    delete[] newArr;
}

void reArrange_InPlace(int arr[], int size){
    int j = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < 0){
            if(i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

void swap(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;

}

int main(){
    int size = 7;
    int arr1[size] = {10, -2, 20, 4, 5, -9, 0};
    int arr2[size] = {10, -2, 20, 4, 5, -9, 0};

    std::cout << "Using New ARRAY: "<<endl;
    reArrange_UsingNewArray(arr1, size);
    for(int i = 0; i < size; i++)
        std::cout<<arr1[i]<< " ";


    std::cout << endl << "Using In-Place: "<<endl;
    reArrange_InPlace(arr2, size);
    for(int i = 0; i < size; i++)
        std::cout<<arr2[i]<< " ";

    return 0;
}