#include <iostream>
#include <vector>
using namespace std;

//vector is a resizeable array automatically

int main(){
    vector<string> strings; //size may or may not be set
    strings.push_back("one"); //using pushback we do not need to set size of vector while declaring
    strings.push_back("two"); //this dynamically increases the size of the vector
    strings.push_back("three");

    for(int i = 0; i<strings.size(); i++){
        cout <<strings[i]<<endl;
    }

    //this iterator object points to the first value of the vector
    //this iterator object overloads the * operator and can be de-referenced
    vector<string>::iterator it = strings.begin();
    cout<<*it<<endl;
    it++; //this overload the + operator, similarly for --

    //can be also done for it += 2 and so on

    for(vector<string>::iterator itr = strings.begin(); itr != strings.end(); itr++)
        cout<<*itr<<endl;

    cout<<"----------------Vector and Memory------------------"<<endl;

    vector <double> numbers(0);
    cout<<"Size: "<<numbers.size()<<endl;

    //vector increases the capacity by creating a new array and copying the existing values into the newly created array
    //this increase is done exponentially
    int capacity = numbers.capacity(); //capacity is the size of the array vector is using
    cout<<"Capacity: "<<capacity<<endl;
    for(int i = 0; i<10000; i++){
        if(numbers.capacity() != capacity){
            capacity = numbers.capacity();
            cout<<"Capacity: "<<capacity<<endl;
        }
        numbers.push_back(i);
    }
    cout<<"Size: "<<numbers.size()<<endl;
    cout<<"Capacity: "<<capacity<<endl;

    numbers.clear(); //removes all the elements in the vector, but capacity does not change
    cout<<"Size: "<<numbers.size()<<endl;
    cout<<"Capacity: "<<capacity<<endl;

    numbers.resize(100); //changes the size up or down, not changing capacity
    cout<<"Size: "<<numbers.size()<<endl;
    cout<<"Capacity: "<<capacity<<endl;

    numbers.reserve(100); //increase the size of internal array of the vector, i.e. capacity is changed
    cout<<"Size: "<<numbers.size()<<endl;
    cout<<"Capacity: "<<capacity<<endl;

    return 0;
}
