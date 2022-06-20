#ifndef MAP_H
#define MAP_H

#include "rbtree.h"

template<class K, class V>
class Map
    {
        struct MapKeyOfT
       {
            const K& operator()(const pair<const K, V>& kv){
                return kv.first;
            }
        };
    public:
        typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

        iterator begin()
        {
            return _t.begin();
        }

        iterator end()
        {
            return _t.end();
        }

        pair<iterator,bool> insert(const pair<const K, V>& kv)
        {
            return _t.insert(kv);
        }

        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = Insert(make_pair(key, V()));
            iterator it = ret.first;
            return it->second;
        }

        iterator find(const K& key)
        {
            return _t.Find(key);
        }

    private:
        RBTree<K,pair<const K, V>, MapKeyOfT> _t;
    };

#endif // MAP_H
