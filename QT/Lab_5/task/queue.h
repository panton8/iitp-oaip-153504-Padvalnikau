#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <memory>


template <class T> class Queue;

template<class T>class Node {

    friend class Queue<T>;

public:
    explicit Node(T val): _data{val}{}
    ~Node() {}

    Node(const Node&) = default;
    Node(Node&&) = default;
    Node& operator=(const Node&) = default;
    Node& operator=(Node&&) = default;

    T _data;
    std::shared_ptr<Node<T>> next = nullptr;
    std::weak_ptr<Node> prev;
    };
template <class T> class Queue{
protected:
    std::shared_ptr<Node<T>> Head;
    std::shared_ptr<Node<T>> Tail;
    unsigned _size;
public:

    Queue();
    ~Queue() {}
    void push_Head(T item);
    void pop();
    const unsigned size();
    const T front();
    const T back();
    bool isEmpty();
};




template <class T>
inline Queue<T>::Queue() : _size{ 0 }, Head { nullptr }, Tail{ nullptr } {}

template <class T>
bool Queue<T>::isEmpty()
{
    return Head == nullptr;
}

template <class T>
void Queue<T>::push_Head(T item)
{
    std::shared_ptr<Node<T>> new_end = std::make_shared<Node<T>>(item);

    if (Tail)
    {
        Tail->next = new_end;
    }
    Tail = new_end;
    if (!Head)
    {
        Head = Tail;
    }
    ++_size;

}

template <class T>
void  Queue<T>::pop()
{
    if (Head == nullptr)
        return;
    auto ptr = std::move(Head);
    Head = ptr->next;
    if (!Head)
    {
        Tail.reset();
    }
    --_size;
}

template <class T>
const unsigned Queue<T>::size()
{
    return _size;
}

template <class T>
const T Queue<T>::front()
{
    if (Head)
        return Head->_data;

    return NULL;
}

template <class T>
const T Queue<T>::back()
{
    if (Tail)
        return Tail->_data;

    return NULL;
}

#endif // QUEUE_H
