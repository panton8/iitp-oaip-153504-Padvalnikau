#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <queue.h>
#include <vector>

template <class T>
class DoubleList : public Queue<int>{
public:
    void push_Head (T x);
    void push_Tail (T x);
    std::vector<T> get_nodes_forward() ;
    std::vector<T> get_nodes_reverse ();
    int length;
};

template<typename T>
void DoubleList<T>::push_Head(T x)
{
    const auto n = std::make_shared<Node<T>>(x);
    if(!Head) {
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
    const auto  temp = std::make_shared<Node<T>>(x);
    if( not Tail) {
        Head = temp;
        Tail = temp;
    } else {
        Tail->next = temp;
        temp->prev = Tail;
        Tail = temp;
    }
     length++;
}

template<typename T>
std::vector<T> DoubleList<T>::get_nodes_forward()
{
    auto temp = Head;
    std::vector<T> out;
    while(temp) {
        out.push_back(temp->_data);
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
        out.push_back(temp->_data);
        temp = temp->prev.lock();
    }
    return out;
}

#endif // DOUBLELIST_H
