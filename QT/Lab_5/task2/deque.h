#ifndef Deque_H
#define Deque_H
#include <new.h>

template<class T>class Deque;

template<class T>class Node {

    friend class Deque<T>;

public :
    Node() : prev(nullptr), next(nullptr), data() {};             // default constructor
    explicit Node(const T & data) : prev(nullptr), next(nullptr), data(data) {}; // prevent implicit conversion
    Node(const Node<T> & other) : prev(nullptr), next(nullptr), data(other.data) {};   // copy constructor

    Node<T> &   operator=(const Node<T> & other) { // copy assignment
        data.~T();
        new (&data) T(other.data);
        return *this;
    };

    const T &    Data() const{
        return data;
    };

    T &Data(){
        return data;
    };

    Node<T> * Prev() const{
        return prev;
    };
    Node<T> * Next() const {
        return next;
    };

private:

    Node<T> *prev;
    Node<T> *next;
    T data;
};

template <class T>
class Deque {
    class Iterator{
        public:
            Iterator(T *ptr): _ptr(ptr){};
            ~Iterator(){};
            bool operator == (const Iterator& rhs) const
            {
                return _ptr == rhs._ptr;
            };

            bool operator != (const Iterator& rhs) const
            {
                return !(*this == rhs);
            };

            Iterator& operator = (const Iterator &rhs)
            {
                _ptr = rhs._ptr;
            };

            bool operator > (const Iterator &rhs)
            {
                return _ptr > rhs;
            };

            bool operator < (const Iterator &rhs)
            {
                return _ptr < rhs;
            };

            bool operator >= (const Iterator &rhs)
            {
                return _ptr >= rhs;
            };

            bool operator <= (const Iterator &rhs)
            {
                return _ptr <= rhs;
            };

            T operator + (const Iterator rhs)
            {
                return _ptr + rhs;
            };

            T operator - (const Iterator rhs)
            {
                return _ptr - rhs;
            };

            T operator += (const Iterator rhs)
            {
                return _ptr + rhs;
            };

            T operator -= (const Iterator rhs)
            {
                return _ptr - rhs;
            };

            T& operator*() const
            {
                return *_ptr;
            };

            T* operator->()
            {
                return _ptr;
            };

            T* operator&()
            {
                return _ptr;
            };

            Iterator& operator++()
            {
                _ptr++;
                return *this;
            }

            Iterator& operator--()
            {
                _ptr++;
                return *this;
            }

        private:
            T *_ptr = nullptr;
        };

public:
    Deque();                                   // default constructor
    Deque(const Deque<T> & other);         // copy constructor
    ~Deque();                                   // destructor

    Deque<T>&operator=(const Deque<T> & other);      // copy assignment

    void PushFront(const T & data);
    void PushBack(const T & data);
    void PopFront();
    void PopBack();

    Node<T> *Back() const;
    Node<T> *Front() const;
    Node<T> *FromFront(int index) const;
    Node<T> *FromBack(int index) const;

    void Clear();
    int Size() const;
    bool IsEmpty() const;

private:

    Node<T> *       front;
    Node<T> *       back;
    int                 nodeCount;
};


template <class T>
inline Deque<T>::Deque() : nodeCount(0), front(nullptr), back(nullptr) {
}


template <class T>
inline Deque<T>::Deque(const Deque<T> & other) {
    Node<T> * otherIterator;

    for (otherIterator = other.back; otherIterator != nullptr; otherIterator = otherIterator->next)
        PushFront(otherIterator->data);
}


template <class T>
inline Deque<T>::~Deque() {
    Clear();
}


template <class T>
inline Deque<T> & Deque<T>::operator=(const Deque<T> & other) {
    Node<T> * thisIterator;
    Node<T> * otherIterator;
    Node<T> * newFront;


    // destroy and reconstruct pre-allocated memory if *this already has some
    for (thisIterator   = back,               otherIterator  = other.back;
         thisIterator  != nullptr     &&      otherIterator != nullptr;
         thisIterator   = thisIterator->next, otherIterator  = otherIterator->next)
        (*thisIterator) = (*otherIterator);     // DEBUG: Node copy assignemnt

    // establish a newFront if *this had more nodes than other
    newFront = nullptr;
    if (thisIterator != nullptr && otherIterator == nullptr)
        newFront = thisIterator->prev;

    // if *this had more nodes, pop all the nodes beyond other's size, down to newFront
    while (thisIterator != newFront) {
        PopFront();
        thisIterator = front;
    }

    // if *this had fewer nodes, push all the data remaining in other onto *this
    for (/*continue moving*/; otherIterator != nullptr; otherIterator = otherIterator->next)
        PushFront(otherIterator->data);

    return *this;
}

/* Deque::PushFront
// copies the data into a new node and links it to the front
*/
template <class T>
inline void Deque<T>::PushFront(const T & data) {
    Node<T> * newFront;

    newFront = new Node<T>(data);
    if (front == nullptr) {
        front = newFront;
        back = newFront;
    } else {
        newFront->prev = front;
        front->next = newFront;
        front = newFront;
    }
    nodeCount++;
}

/* Deque::PushBack
// copies the data into a new node and links it to the back
*/
template <class T>
inline void Deque<T>::PushBack(const T & data) {
    Node<T> * newBack;

    newBack = new Node<T>(data);
    if (back == nullptr) {
        back = newBack;
        front = newBack;
    } else {
        newBack->next = back;
        back->prev = newBack;
        back = newBack;
    }
    nodeCount++;
}

//******************
// Deque::PopFront
// unlinks and deletes the front node
//******************
template <class T>
inline void Deque<T>::PopFront() {
    Node<T> * newFront;
    Node<T> * oldFront;

    if (front->prev == nullptr) {           // last node in the deque
        delete front;
        front = nullptr;
        back = nullptr;
    } else {                                // more than one node in the deque
        oldFront = front;
        newFront = front->prev;
        newFront->next = nullptr;
        front = newFront;
        delete oldFront;
    }
    nodeCount--;
}

//******************
// Deque::PopBack
// unlinks and deletes the back node
//******************
template <class T>
inline void Deque<T>::PopBack() {
    Node<T> * newBack;
    Node<T> * oldBack;

    if (back->next == nullptr) {            // last node in the deque
        delete back;
        front = nullptr;
        back = nullptr;
    } else {                                // more than one node in the deque
        oldBack = back;
        newBack = back->next;
        newBack->prev = nullptr;
        back = newBack;
        delete oldBack;
    }
    nodeCount--;
}

//******************
// Deque::Front
//******************
template <class T>
inline Node<T> * Deque<T>::Front() const {
    return front;
}

//******************
// Deque::Back
//******************
template <class T>
inline Node<T> * Deque<T>::Back() const {
    return back;
}

//******************
// Deque::FromFront
// returns the node "index" nodes behind the front
// index between [ 0, Size() - 1 ]
// returns nullptr for out-of-bounds index or empty deque
//******************
template <class T>
inline Node<T> * Deque<T>::FromFront(int index) const {
    Node<T> * iterator;
    int i;

    if (index >= nodeCount || index < 0)
        return nullptr;

    if (index == nodeCount - 1)
        return back;

    i = 0;
    iterator = front;
    while (i++ < index)
        iterator = iterator->prev;

    return iterator;
}

//******************
// Deque::FromBack
// returns the node "index" nodes ahead of the back
// index between [ 0, Size() - 1 ]
// returns nullptr for out-of-bounds index or empty deque
//******************
template <class T>
inline Node<T> * Deque<T>::FromBack(int index) const {
    Node<T> * iterator;
    int i;

    if (index >= nodeCount || index < 0)
        return nullptr;

    if (index == nodeCount - 1)
        return front;

    i = 0;
    iterator = back;
    while (i++ < index)
        iterator = iterator->next;

    return iterator;
}

//******************
// Deque::Clear
// unlinks and deletes all nodes front to back
//******************
template <class T>
inline void Deque<T>::Clear() {
    while (!IsEmpty())
        PopFront();
}

//******************
// Deque::Size
// current number of nodes
//******************
template <class T>
inline int Deque<T>::Size() const {
    return nodeCount;
}

//******************
// Deque::IsEmpty
// returns true for front == nullptr
//******************
template <class T>
inline bool Deque<T>::IsEmpty() const {
    return front == nullptr;
}


#endif // Deque_H
