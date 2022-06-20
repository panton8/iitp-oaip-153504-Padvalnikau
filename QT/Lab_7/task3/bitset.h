#ifndef BITSET_H
#define BITSET_H
#include<string>
using namespace std;

#define N 4
const int max_length = 8 * N;
class bitset {
private:
    unsigned long long  a[N];
public:
    bitset();
    void set(int pos);
    void reset(int pos);
    int count() const;
    bool test(int pos) const;
    bool any() const;
    bool none() const;
    bool all() const;
    string toString();
    int size();
    void flip();
    unsigned long to_ulong();
    unsigned long long to_ullong();

    bitset &operator&=(const bitset &b);

    bitset &operator|=(const bitset &b);

    bitset &operator^=(const bitset &b);

    bitset &operator=(const bitset &b);

    bitset &operator<<=(int pos);

    bitset &operator>>=(int pos);

    bitset operator~() const;

    bitset operator&(const bitset &b) const;

    bitset operator|(const bitset &b) const;

    bitset operator^(const bitset &b) const;

    bitset operator<<(int pos) const;

    bitset operator>>(int pos) const;

    bool operator==(const bitset &b) const;

    bool operator!=(const bitset &b) const;

    bool operator[](int pos) const;
};

#endif // BITSET_H
