#include "array.h"

template<class T>
Array<T>::Array()
{
    _size = 0;
    _buf = new T[1];
    _capacity = 1;
}

template<class T>
Array<T>::Array(int s, const T& a)
{
    if (s > _max_capacity) {
        s = _max_capacity;
    }
    _size = s;
    _capacity = 1;
    while (_capacity < _size) {
        _capacity *= 2;
    }
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _buf[i] = a;
    }
}
template<class T>
Array<T>::Array(const Array<T> & a)
{
    _size = a._size;
    _capacity = a._capacity;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _buf[i] = a._buf[i];
    }
}
template<class T>
Array<T>::~Array()
{
    delete[] _buf;
}

template<class T>
int Array<T>::size() const
{
    return _size;
}

template<class T>
T& Array<T>::operator[](int index)
{
    return _buf[index];
}

template<class T>
void Array<T>::push_back(const T& val)
{
    T * tmp = new T[++_size];
    for (int i = 0; i < _size-1; i++) {
        tmp[i] = _buf[i];
    }
    tmp[_size-1] = val;
    delete[] _buf;
    qDebug() << _size;
    _buf = tmp;
}

template<class T>
void Array<T>::push_front(const T& val)
{
    T * tmp = new T[++_size];
    for (int i = 1; i < _size; i++) {
        tmp[i] = _buf[i-1];
    }
    tmp[0] = val;
    delete[] _buf;
    _buf = tmp;
}

template<class T>
void Array<T>::push_insert(int a, const T& val)
{
    if(a==0){
        push_front(val);
        return;
    }
    if(a==size()){
        push_back(val);
        return;
    }
    if (_size < _capacity) {
        _buf[_size] = val;
        _size++;
        return ;
    } else if (_size == _max_capacity) {
        return ;
    }

    T * tmp = new T[++_size];

    for (int i = 0; i < a; i++) {
        tmp[i] = _buf[i];
    }
    tmp[a] = val;
    for (int i = a+1; i < size(); i++) {
        tmp[i] = _buf[i-1];
    }
    delete[] _buf;
    _buf = tmp;
}


template<class T>
void Array<T>::deleteNum(int a, const T& val)
{
    T * tmp = new T[_size];
    for (int i = 0; i < a; i++) {
        tmp[i] = _buf[i];
    }
    for (int i = a; i < size()-1; i++) {
        tmp[i] = _buf[i+1];
    }
    _size--;
    delete[] _buf;
    _buf = tmp;
}


template<class T>
void Array<T>::pop_back()
{
    _size--;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T> & a)
{
    if (this == &a) {
        return *this ;
    }
    delete[] _buf;
    _size = a._size;
    _capacity = a._capacity;
    _buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _buf[i] = a._buf[i];
    }
    return *this;
}
