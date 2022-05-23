#ifndef STACK_H
#define STACK_H

#include <iostream>
template<typename T>
struct Element {

    T element;
    Element* next;
};

template<typename T>
class Stack {

private:

    Element<T>* top;

public:

    Stack() : top(nullptr) {}
    ~Stack() {

        while (!isEmpty())
            pop();

    }

    size_t size() {

        size_t i = 0;

        Element<T>* cur;

        for (cur = top; cur != nullptr; cur = cur->next)
            ++i;

        return i;

    }

    void push(T new_element) {

        Element<T>* temp = new Element<T>;

        temp->element = new_element;

        temp->next = top;
        top = temp;
    }

    T pop() {

        if (!isEmpty()) {
            T value = top->element;

            Element<T>* oldtop = top;
            top = oldtop->next;
            delete oldtop;

            return value;
        }
        else {
            return T();
        }
    }

    T Top() {

        return top->element;
    }

    bool isEmpty() {
        return !top;
    }

};

#endif // STACK_H
