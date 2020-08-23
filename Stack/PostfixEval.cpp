#include <iostream>
#include "Stack.h"
using namespace std;

int postfixEvaluate(string exp){

    myStack stack(exp.length());
    char character;
    int x, y;

    for(int i = 0; i < exp.length(); i++){
        character = exp[i];

        if(!isdigit(character)){
            x = stack.pop();
            y = stack.pop();

            switch(character){
                case '+':
                    stack.push(x + y);
                    break;
                case '-':
                    stack.push(x - y);
                    break;
                case '*':
                    stack.push(x * y);
                    break;
                case '/':
                    stack.push(x / y);
                    break;
            }
        }
        else
            stack.push(character);
    }
    return stack.pop();
}

int main(){
    std::cout<<endl<<postfixEvaluate("921*-8-4+");
}