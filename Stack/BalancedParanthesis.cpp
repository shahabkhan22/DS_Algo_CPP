#include <iostream>
#include "Stack.h"
using namespace std;

bool isBalancedParanthesis(string exp){
    int size = exp.length();
    myStack stack(size);

    for(int i = 0; i < size; i++){
        char current = exp[i];


        if(current == ']' || current == '}' || current == ')'){

            if(stack.isEmpty())
                return false;

            if((current == '}' && stack.pop() != '{' ) || (current == ']' && stack.pop() != '[' ) || (current == ')' && stack.pop() != '(' ))
                return false;

        }
        else
            stack.push(current);

    }

    if(!stack.isEmpty())
        return false;

    return true;
}

int main(){
    std::cout<<isBalancedParanthesis("{[{[()]}]}")<<endl;
}