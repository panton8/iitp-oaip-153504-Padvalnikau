#ifndef STACK_H
#define STACK_H
#define MAX 300

class Stack
{
public:
    int top;
public:
    double stack[MAX];
    Stack();
    bool push(double x);
    double pop();
    double Top();
    bool isEmpty();
};

#endif // STACK_H
