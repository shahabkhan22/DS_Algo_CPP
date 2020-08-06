#include <iostream>
using namespace std;

int *removeEven(int *&Arr, int size){
    int m = 0;
    for(int i=0; i< size; i++){
        if(Arr[i] %2 != 0){
            if(i != m){
                Arr[m] = Arr[i];
            }
            ++m;
        }
    }
    int *temp = new int[m];
    for(int i =0; i<m; i++)
        temp[i] = Arr[i];

    delete [] Arr;
    Arr = temp;
    return Arr;
}

int main(){
    int *arr;
    arr = new int[10];
    for(int i = 0; i <10; i++)
        arr[i]= i;
    std :: cout << "Before Removing Even: ";
    for(int i = 0; i <10; i++)
        std::cout << arr[i] << " ";
    std :: cout << endl;
    arr = removeEven(arr, 10);
    std :: cout << "After Removing Even: ";
    for(int i = 0; i <5; i++)
        std::cout << arr[i] << " ";
    delete []arr;
    return 0;
}
