#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(): name(""), age(0){}

    Person(string name, int age){ //this causes compilation failure as a map need a default constructor with no parameters
        this->name = name;
        this->age = age;
    }
    //Default copy constructor performs shallow copy
    Person(const Person &other){

        name = other.name;
        age = other.age;
    }
    void print() const{ //const so print cannot change values
        cout << this->name <<" : "<<this->age << flush;
    }
    //to use objects as keys, we need to overload the < operator
    //this is because the map orders the key,value pairs stored in it
    //and their is no way to compare which is lower ordered value as
    //the key being used in the map is object of class Person
    //const other  and const funtion so overloading funtion doesn't
    //change both the objects passed for comparison
    bool operator<(const Person &other) const{
        cout<<"Inside Operator <'s Overloaded Method"<<endl;
        return name < other.name;
    }
};

int main(){


    map<Person, int> people;

    people[Person("ABC", 10)] = 10;
    cout<<"1st Key,Value Pair inserted"<<endl;
    people[Person("PQR", 20)] = 20;
    cout<<"2nd Key,Value Pair inserted"<<endl;
    people[Person("MNS", 40)] = 40;
    cout<<"3rd Key,Value Pair inserted"<<endl;

    for(map<Person, int>::iterator it = people.begin(); it != people.end(); it++){
        cout<<"Printing First Map Value"<<endl;
        cout<<it->second<<": "<<flush;
        it->first.print(); //iterator returns keys as const values, but print isn't const
        cout<<endl;
    }

    return 0;
}