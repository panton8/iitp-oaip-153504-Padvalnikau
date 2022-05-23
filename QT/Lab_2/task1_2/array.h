#ifndef ARRAY_H
#define ARRAY_H

#include <QMainWindow>
#include <QDebug>
template < class T>
class Array{
public:
    typedef T * iterator;

    Array();
    Array(int size, T const& a);
    Array(const Array<T> & a);
    ~Array();
    int size() const;
    void push_back(const T& val);
    void push_front(const T& val);
    void push_insert(int,const T& val);
    void deleteNum(int,const T& val);
    void pop_back();
    T& operator[](int index);
    Array<T>& operator=(const Array<T>& a);
private:
    int  _size;
    int  _capacity;
    T*      _buf;
    const int _max_capacity = 65536;
};

#endif // ARRAY_H
