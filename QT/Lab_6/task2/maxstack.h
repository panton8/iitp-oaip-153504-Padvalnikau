#ifndef MAXSTACK_H
#define MAXSTACK_H
#include "hashtable.h"

class MaxStack : public HashTable<int>
{
public:
    MaxStack();
    int maxStack();
};

#endif // MAXSTACK_H
