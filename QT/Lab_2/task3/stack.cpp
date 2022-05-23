#include "stack.h"

Stack::Stack(){
    top = -1;
}

bool Stack::push(double x)
{
    if (top >= (MAX - 1))
        return false;
    else {
        stack[++top] = x;
        return true;
    }
}

double Stack::pop()
{
    if (top >= 0){
        double x = stack[top--];
        return x;
    }
}

double Stack::Top()
{
    if (top >= 0) {
        double x = stack[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return top < 0;
}
