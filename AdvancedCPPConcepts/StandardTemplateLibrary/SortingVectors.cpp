#include <iostream>
#include <vector>
using namespace std;

class Test{
    int id;
    string name;
public:
    Test(int id, string name): id(id), name(name){}

    void print(){
        cout<<id<<" : "<<name<<endl;
    }

    bool operator<(const Test &obj1) const{
        return name < obj1.name;
    }
};

int main(){
    vector<Test> tests;

    tests.push_back(Test(1, "ABC"));
    tests.push_back(Test(4, "MNC"));
    tests.push_back(Test(3, "DEF"));
    tests.push_back(Test(2, "PQR"));

    sort(tests.begin(), tests.end());

    for(int i = 0; i< tests.size(); i++){
        tests[i].print();
    }

    return 0;
}