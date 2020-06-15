#include <iostream>
#include <memory>
#include "stack.h"

using std::unique_ptr;

int main()
{
    unique_ptr<Stack<int>> stk(new Stack<int>()); //stack smart pointer
    std::cout<<"ARE THE PARANTHESIS BALANCED?\n";
    std::cout<<"Type in a String of Parenthesis then press ENTER\n";
    //code for intercting with the stack
    char temp = 0;
    while (1) {
        std::cin.get(temp);
        if(temp == '\n') {break;}
        else if (temp == '(') {stk->push(0);}
        else if (temp == ')') {stk->pop();}
        else {
            std::cout<<"You have entered a bad character - terminated\n";
            return 1;
        }
    }
    //the verdict
    if(stk->empty()) {
        std::cout<<"Parenthesis are Balanced\n";
    }
    else{
        std::cout<<"Parenthesis are not Balanced\n";
    }
    return 0;
}
