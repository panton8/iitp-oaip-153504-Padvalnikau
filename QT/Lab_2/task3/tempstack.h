#ifndef TEMPSTACK_H
#define TEMPSTACK_H
#define MAX 300
#include <QChar>

class TempStack
{
public:
    int top;
public:
    QChar tempStack[MAX];
    TempStack();
    bool push(QChar x);
    QChar pop();
    QChar Top();
    bool isEmpty();
};

#endif // TEMPSTACK_H
