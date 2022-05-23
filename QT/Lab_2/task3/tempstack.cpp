#include "tempstack.h"

TempStack::TempStack(){
    top = -1;
}

bool TempStack::push(QChar x)
{
    if (top >= (MAX - 1))
        return false;
    else {
        tempStack[++top] = x;
        return true;
    }
}

QChar TempStack::pop()
{
    if (top >= 0){
        QChar x = tempStack[top--];
        return x;
    }
}

QChar TempStack::Top()
{
    if (top >= 0) {
        QChar x = tempStack[top];
        return x;
    }
}

bool TempStack::isEmpty(){
    return top < 0;
}
