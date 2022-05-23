#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include<memory>
#include <vector>
#include <mainwindow.h>
#include "ui_mainwindow.h"

template<typename T>
struct Node {
    explicit Node(T val): value{val}{}
    ~Node() {}

    Node(const Node&) = default;
    Node(Node&&) = default;
    Node& operator=(const Node&) = default;
    Node& operator=(Node&&) = default;

    T value;
    std::shared_ptr<Node> next = nullptr;
    std::weak_ptr<Node> prev; // using a shared_ptr would introduce circular dependencies
};

template<typename T>
class DoubleList {
public:
    void push_Head (T x);
    void push_Tail (T x);
    std::vector<T> get_nodes_forward() ;
    std::vector<T> get_nodes_reverse ();
    int length;
private:
    std::shared_ptr<Node<T>> Head = nullptr;
    std::shared_ptr<Node<T>> Tail = nullptr;
};

template<typename T>
void DoubleList<T>::push_Head(T x)
{
    const auto n = std::make_shared<Node<T>>(x);
    if( !Head) {
        Head = n;
        Tail = n;
    } else {
        Head->prev = n;
        n->next = Head;
        Head = n;
    }
    length++;
}

template<typename T>
void DoubleList<T>::push_Tail(T x)
{
    const auto n = std::make_shared<Node<T>>(x);
    if( not Tail) {
        Head = n;
        Tail = n;
    } else {
        Tail->next = n;
        n->prev = Tail;
        Tail = n;
    }
     length++;
}

template<typename T>
std::vector<T> DoubleList<T>::get_nodes_forward()
{
    auto temp = Head;
    std::vector<T> out;
    while(temp) {
        out.push_back(temp->value);
        temp = temp->next;
    }
    return out;
}

template<typename T>
std::vector<T> DoubleList<T>::get_nodes_reverse()
{
    auto temp = Tail;
    std::vector<T> out;
    while(temp) {
        out.push_back(temp->value);
        temp = temp->prev.lock();
    }
    return out;
}

#endif // DOUBLELIST_H
