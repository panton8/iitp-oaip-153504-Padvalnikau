#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include"sharedptr.h"
#include <memory>

struct Node
{
    short data;
    WeakPtr<Node> prev;
    SharedPtr<Node> next;
};

class DoubleList
{
public:
    DoubleList();
    ~DoubleList();
public:
    void add(int numb);

    void popback();
    void insert(int pos, int numb);
    void erase(int pos);
    int getLength();
    int getData(int pos);
private:
    int length;
    Node* root;
};

#endif // DOUBLELIST_H
