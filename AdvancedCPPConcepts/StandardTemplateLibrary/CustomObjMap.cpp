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

    Person(const Person &other){
        cout<<"Copy Constructor Running"<<endl;
        name = other.name;
        age = other.age;
    }
    void print() {
        cout << this->name <<" : "<<this->age << endl;
    }
};

int main(){

    map<int, Person> people;

    people[0] = Person("ABC", 10); //this people[0] needs a default constructor to construct the object
    people[1] = Person("PQR", 20); //providing no such default constructor causes a compilation error
    people[2] = Person("MNO", 40);

    people.insert(make_pair(55, Person("LMN", 45)));

    for(map<int, Person>::iterator it = people.begin(); it != people.end(); it++){
        it->second.print();
    }

    return 0;
}