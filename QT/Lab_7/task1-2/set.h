#ifndef SET_H
#define SET_H

#include "rbtree.h"

template<class K>
class Set
{
    struct SetKeyOfT
    {
        const K& operator()(const K& key)
        {
            return key;
        }
    };
public:
    typedef typename RBTree<K, K, SetKeyOfT> ::iterator iterator;

    iterator begin()
    {
        return _t.begin();
    }

    iterator end()
    {
        return _t.end();
    }

    bool insert(const K& k)
    {
        _t.insert(k);
        return true;
    }

    iterator find(const K& key)
    {
        return _t.Find(key);
    }

private:
    RBTree<K, K, SetKeyOfT> _t;
};

#endif // SET_H
