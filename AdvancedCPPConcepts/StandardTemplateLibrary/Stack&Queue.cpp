#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test{
private:
    string name;
public:
    Test(string name): name(name){}

    ~Test(){}

    void print(){
        cout<<name<<endl;
    }
};

int main(){

    stack<Test> testStack;
    testStack.push(Test("ABC"));
    testStack.push(Test("PQR"));
    testStack.push(Test("XYZ"));

    Test &test1 = testStack.top(); //this return a reference but doesn't actually pops
    test1.print();

    testStack.pop(); //this has void return type
    testStack.push(Test("XYZ"));


    //Test test2 = testStack.pop();
    return 0;
}