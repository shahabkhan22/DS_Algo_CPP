#include <iostream>
#include <set>
using namespace std;

int main(){

    set<int> numbers;

    numbers.insert(10);
    numbers.insert(124);
    numbers.insert(1345);
    numbers.insert(98237);
    numbers.insert(-2);

    for(auto it = numbers.begin(); it != numbers.end(); it++){
        cout<<*it<<endl;
    }

    set<int>::iterator itFind = numbers.find(12);
    if(itFind != numbers.end())
        cout <<"Number Found"<<endl;
    else
        cout<<"Number Not Found"<<endl;

    //can use the class objects as well
    //similar to maps
    
    return 0;
}