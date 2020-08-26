#include <iostream>
#include <map>
using namespace std;

int main(){
    //allows to store key,value pairs
    //like a lookup table
    //keys are unique
    //map orders the values in order of its keys
    map<string, int> age;

    //to add items use overloaded array subscript operator
    age["ABC"] = 40;
    age["PQR"] = 20;
    age["XYZ"] = 10;

    //simply using the not added values adds it to the map
    std::cout<<age["ABC"]<<endl;

    age["ABC"] = 50;

    //search a value in the map
    if(age.find("Sue") != age.end()){
        std::cout<<"Found Sue"<<endl;
    }
    else
        std::cout<<"Key Not Found"<<endl;

    //iterating through maps is complicated as key,value
    //first refers to the key, second refers to the value
    for(map<string, int>::iterator it = age.begin(); it != age.end(); it++){
        std::cout<<it->first<<": "<<it->second<<endl;
        //it is of type pair, which is another template type
    }

    cout<<endl<<endl;
    age.insert(pair<string, int>("MNO", 15)); //another way to add using pair
    age.insert(make_pair("LMN", 100)); //another way to addd, make_pair return the right type of iterator pair
    for(map<string, int>::iterator it = age.begin(); it != age.end(); it++){
        pair<string, int> ages = *it;
        cout<<ages.first<<" : "<<ages.second<<endl;
    }

    return 0;
}