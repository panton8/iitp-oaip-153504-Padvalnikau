#include "stack.h"

Stack::Stack(){ 
    top = -1;
}

bool Stack::push(QChar x)
{
    if (top >= (MAX - 1))
        return false;
    else {
        stack[++top] = x;
        return true;
    }
}

QChar Stack::pop()
{
    if (top >= 0){
        QChar x = stack[top--];
        return x;
    }
}

QChar Stack::Top()
{
    if (top >= 0) {
        QChar x = stack[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return top < 0;
}
