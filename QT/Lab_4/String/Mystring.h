#ifndef MYSTRING_H
#define MYSTRING_H

#include "String_global.h"
#include <iostream>

 using namespace std;

class STRING_EXPORT MyString
{
private:
    char* str;
    int length;
public:
    MyString();
    MyString(const char* cs, const size_t& n);
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other);
    MyString(const MyString& s, const size_t& pos, const size_t& n);
    MyString(const size_t& n, const char& c);

    ~MyString();

    MyString& operator =(const MyString& other);

    MyString operator+(const MyString& other);

    void Print();

    int Length();

    bool operator ==(const MyString& other);

    bool operator !=(const MyString& other);

    char& operator [](int index);


    void clear();

    bool empty();

    MyString& operator+=(const char& c);

    MyString& operator+=(const char* cs);

    MyString& operator+=(const MyString& s);

    MyString& append(const char* cs);

    MyString& append(const MyString& s);

    int compare(const MyString& s) const;

    MyString& insert(const size_t& pos, const char* cs);

    MyString& insert(const size_t& pos, const MyString& s);

    MyString& insert(const size_t& pos, const char* cs, const size_t& n);

    MyString& insert(const size_t& pos1, const MyString& s, const size_t& pos2, const size_t& n);

    MyString& insert(const size_t& pos, const size_t& n, const char& c);


    MyString& erase(const size_t& pos, const size_t& n);

    MyString& erase(const size_t& pos);

    const char* c_str() const;

    const char& at(const size_t& pos) const;

    char& at(const size_t& pos);

    void push_back(const char& c);

    MyString substr(const size_t& pos, const size_t& n);

    MyString& replace(const size_t& pos, const size_t& n, const MyString& s);

    MyString& replace(const size_t& pos1, const size_t& n1, const MyString& s, const size_t& pos2, const size_t& n2);

    MyString& replace(const size_t& pos, const size_t& n1, const char* cs, const size_t& n2);

    void pop_back() ;

    int find (const MyString& other, size_t start = 0) const ;

    void resize(size_t newSize);

    void resize(size_t newSize, const char& elem);


    void expandString(const size_t& n);

    void* Mymemset(void* dest, int val, size_t len);

    void* Mymemcpy(void* s1, const void* s2, size_t n);

    int Mymemcmp(const void* str1, const void* str2, size_t count);

    void* Mymemmove(void* dest, const void* src, size_t len);

    int Mystrncmp(const char* str1, const char* str2, size_t num);

    char* Mystrncat(char* dest, char const* src, size_t  n);

    char* Mystrncpy(char* dest, char* src, size_t num);

    size_t Mystrlen(const char* s);

    char* Mystrcpy(char* destptr, const char* srcptr);
};


#endif // MYSTRING_H
