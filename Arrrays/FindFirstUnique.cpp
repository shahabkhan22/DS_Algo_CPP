#include <iostream>
using namespace std;

int findFirstUnique_BruteForce(int arr[], int size){
    bool isRepeated = false;

    for(int i = 0; i< size; i++){
        for(int j = 0; j< size; j++){
            if(arr[i] == arr[j] && i != j)
                isRepeated = true;
        }
        if(isRepeated == false)
            return arr[i];
        isRepeated = false;
    }
    return -1;
}
/*
int main(){
    int size = 6;
    int arr[size] = {2,54,7,2,6,54};

    cout << "Array: " ;
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;

    int unique = findFirstUnique_BruteForce(arr,size);
    cout << "First Unique in an Array: " << unique << endl;
    return 0;
}
*/
