#ifndef UN_MAP_H
#define UN_MAP_H
#include <forward_list>
#include <vector>
#include <string>


template<class KeyType,class ValueType>
class un_map
{

    int capacity = 10;
    std::forward_list<std::pair<KeyType, ValueType>>* table;


    KeyType Rehash(KeyType key)
    {
        return key % 15;
    }


    KeyType GetHash(KeyType key)
    {
        return key % 15;
    }


    void Resize()
    {
        capacity *= 2;
        std::forward_list<std::pair<KeyType, ValueType>>* temp = new std::forward_list<std::pair<KeyType, ValueType>>[capacity];
        for (int i = 0; i < capacity / 2; i++)
        {
            for (std::pair<KeyType, ValueType> tmp : table[i])
            {
                temp[Rehash(tmp.first)].push_front(tmp);
            }
            if (!table[i].empty())
            {
                table[i].clear();
            }
        }
        table->clear();
        table = temp;
    }


public:


    un_map()
    {
        table = new std::forward_list<std::pair<KeyType, ValueType>>[capacity];
    }


    void insert(KeyType key, ValueType val)
    {
        while (capacity < GetHash(key))
            Resize();
        table[GetHash(key)].push_front(std::make_pair(key, val));
    }


    std::string Find(KeyType key)
    {
        int index = GetHash(key);
        if (index >= capacity)
            return "Empty";
        for (std::pair<KeyType, ValueType> tmp : table[index])
        {
            if (tmp.first == key)
            {
                return tmp.second;
            }
        }
        return "Empty";
    }


    void Erase(KeyType key)
    {
        int index = GetHash(key);
        if (index > capacity)
            return;
        for (std::pair<KeyType, ValueType> tmp : table[index])
        {
            if (tmp.first == key)
            {
                table[index].remove(tmp);
                return;
            }
        }
    }


    void Clear()
    {
        for (int i = 0; i < capacity; i++)
        {
            table[i].clear();
        }
        table->clear();
    }


    bool Contains(KeyType key)
    {
        std::string answ = Find(key);
        return answ != "Empty" ? true : false;
    }


    ValueType& operator[](KeyType key)
    {
        int index = GetHash(key);
        std::string answ = Find(key);
        if (answ == "Empty")
        {
            Insert(key, "Default");
        }
        typename std::forward_list<std::pair<KeyType, ValueType>>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it)
        {
            if((*it).first == key){
                std::pair<KeyType, ValueType> tmp = *it;
                return (*it).second;
            }
        }
    }

    void ChangeValue(KeyType key, ValueType val)
    {
        int index = GetHash(key);
        std::string answ = Find(key);
        if (answ == "Empty")
        {
            return;
        }
        typename std::forward_list<std::pair<KeyType, ValueType>>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it)
        {
            std::pair<KeyType, ValueType> tmp = *it;
            (*it).second = val;
        }
    }


    ValueType operator[](KeyType key) const
    {
        int index = GetHash(key);
        std::string answ = Find(key);
        if (answ == "Empty")
        {
            Insert(key, "Default");
        }
        typename std::forward_list<std::pair<KeyType, ValueType>>::iterator it;
        for (it = table[index].begin(); it != table[index].end(); ++it)
        {
            if((*it).first == key){
                std::pair<KeyType, ValueType> tmp = *it;
                return (*it).second;
            }
        }
    }
    std::forward_list<std::pair<KeyType,ValueType>> ReturnList(int key){
        return table[key];
    }

    int GetSize()
    {
        return capacity;
    }



};


#endif // UN_MAP_H
