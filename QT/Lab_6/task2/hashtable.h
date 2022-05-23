#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "stack.h"

template<class T>
class HashTable
{
protected:
    Stack<T>** table;
    int size = 0;
    void resize()
    {
        capacity *= 2;
        Stack<T>** temp = new Stack<T>*[capacity];
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = nullptr;
        }
        for(int i = 0; i < capacity / 2;i++)
        {
            temp[i] = table[i];
        }
        delete table;
        table = temp;
    }

public:
    int capacity = 15;

    HashTable()
    {
        table = new Stack<T> * [capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
            delete table[i];
        delete table;
    }

    int GetHash(int key)
    {
        return key % 1087;
    }

    void Add(int key, T value)
    {
        int index = GetHash(key);
        while(index > capacity - 1)
            resize();
        if (table[index] == nullptr)
        {
            Stack<T> *tmp = new Stack<T>();
            tmp->push(value);
            table[index] = tmp;
        }
        else
        {
            Stack<T>* tmp = table[index];
            tmp->push(value);
        }

    }

    void Remove(int key)
    {
        int index = GetHash(key);
        Stack<T>* tmp = table[index];
        if(!tmp->empty())
            tmp->pop();
    }

    Stack<T>* Find(int key)
    {
        int index = GetHash(key);
        Stack<T>* tmp = table[index];
        return tmp;
    }
};

#endif // HASHTABLE_H
