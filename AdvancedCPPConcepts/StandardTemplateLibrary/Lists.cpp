#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_front(10);
    numbers.push_front(9);
    numbers.push_front(8);

    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    cout<<"Element "<<*it<<endl;

    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        cout<<*it<<"->";
    cout<<endl;

    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
        if(*it == 2)
            numbers.insert(it, 1234);

        if(*it == 1)
            it = numbers.erase(it);
        else
            it++;
    }

    cout<<endl;
    
    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        cout<<*it<<"->";



    return 0;
}