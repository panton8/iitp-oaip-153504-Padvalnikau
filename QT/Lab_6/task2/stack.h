#ifndef STACK_H
#define STACK_H




template <class T>
class Stack
{
public:
    int capacity;
    int index;
    T* arr;

    Stack(int capacity = 15) {
        this->capacity = capacity;
        this->index = 0;
        this->arr = new T[capacity];
    }

    void push(T element)
    {
        arr[index++] = element;
    }

    T pop()
    {
        return arr[--index];
    }

    T& top()
    {
        return arr[index - 1];
    }

    bool empty()
    {
        return index == 0;
    }

    int size()
    {
        return index;
    }

};
#endif // STACK_H
