#ifndef STACK_H
#define STACK_H
#define MAX 100000
#include <QChar>

class Stack
{
public:
    int top;
public:
    QChar stack[MAX];
    Stack();
    bool push(QChar x);
    QChar pop();
    QChar Top();
    bool isEmpty();
};

#endif // STACK_H
