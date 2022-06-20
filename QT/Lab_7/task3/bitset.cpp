#include "bitset.h"
#include "cmath"
using namespace std;
#include <algorithm>


bitset::bitset(){
    for(int i = 0; i < N; i++)
        a[i] = 0;
}


void bitset::set(int pos)
{
    int p = pos / 8;
    int t = pos % 8;
    a[p] |= 1<<t;
}


void bitset::reset(int pos)
{
    int p = pos / 8;
    int t = pos % 8;
    a[p] &= ~ (1<<t);
}


int bitset::count() const
{
    int num = 0;
    for (int i = N-1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            if (a[i] & (1 << j))
                num++;
        }
    }
    return num;
}

bool bitset::test(int pos) const
{
    int p = pos / 8;
    int t = pos % 8;
    return (a[p] & (1<<t));
}


bool bitset::any() const
{
    return count() > 0;
}

bool bitset::none()const
{
    return count() == 0;
}

bool bitset::all()const
{
    return max_length == count();
}


bitset& bitset::operator&= (const bitset& m)
{
    for (int i = 0; i < N; i++)
        a[i] &= m.a[i];
    return *this;
}


bitset& bitset::operator|=(const bitset& m)
{
    for (int i = 0; i < N; i++)
        a[i] |= m.a[i];
    return *this;
}


bitset& bitset::operator^=(const bitset& m)
{
    for (int i = 0; i < N; i++)
        a[i] ^= m.a[i];
    return *this;
}


bitset& bitset::operator=(const bitset& m)
{
    for(int i = 0; i < N; i++)
        a[i] = m.a[i];
    return *this;
}


bitset& bitset::operator <<=(int pos)
{
    bitset temp = *this;
    for(int i = 0;i < N;i++)
    {
        a[i] = 0;
    }
    for(int i  = 0;i < 8*N -pos;i++)
    {
        if(temp.test(i)){
            set(i+pos);
        }
        else reset(i+pos);
    }
    return *this;
}


bitset& bitset::operator >>=(int pos)
{
    bitset temp = *this;
    for(int i = 0;i < N;i++)
    {
        a[i] = 0;
    }
    for(int i = pos;i < 8*N;i++)
    {
        if(temp.test(i))
            set(i-pos);
        else
            reset(i-pos);
    }
    for(int i = 0;i < pos;i++)
    {
        set(8*N - 1 - i);
    }
    return *this;
}


bitset bitset::operator~()const
{
    bitset temp;
    for (int i = 0; i < N; i++)
        temp.a[i] = ~a[i];
    return temp;
}


bitset bitset::operator&(const bitset& m) const
{
    bitset temp;
    temp = *this;
    temp &= m;
    return temp;
}


bitset bitset::operator|(const bitset& m) const
{
    bitset temp;
    temp = *this;
    temp |= m;
    return temp;
}


bitset bitset::operator^(const bitset& m)const
{
    bitset temp;
    temp = *this;
    temp ^= m;
    return temp;
}


bitset bitset::operator <<(int pos)const
{
    bitset temp;
    temp = *this;
    temp <<= pos;
    return temp;
}


bitset bitset::operator>>(int pos)const
{
    bitset temp;
    temp = *this;
    temp >>= pos;
    return temp;
}


bool bitset::operator==(const bitset& m) const
{
    for(int i = 0; i < N; i++) {
        if (a[i] != m.a[i])
            return false;
    }
    return true;
}


bool bitset::operator!=(const bitset& m) const
{
    return !(*this == m);
}


bool bitset::operator[](int pos) const {
    if (test(pos))
        return true;
    return false;
}

string bitset::toString(){
    string s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i] & (1 << j))
                s += "1";
            else
                s += "0";
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

void bitset::flip() {
    for (int i = 0; i < 8*N; i++) {
        int p = i / 8;
        int t = i % 8;
        if(a[p] & (1 << t))
            reset(i);
        else
            set(i);
    }
}

int bitset::size(){
    return N*8;
}

unsigned long bitset::to_ulong(){
    string st;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i] & (1 << j))
                st += "1";
            else
                st += "0";
        }
    }
   reverse(st.begin(), st.end());

    unsigned long res = 0;
    for ( int i = 0; i < st.length(); i++)
    {
        res*=2;
        res += st[i] - '0';
    }
    return res;
}

unsigned long long bitset::to_ullong(){
    string str;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i] & (1 << j))
                str += "1";
            else
                str += "0";
        }
    }

    unsigned long long res = 0;
    for(int i = 0; i < N*8; i++){
        if(str[i] == '0')
            res += 0;
        else
            res += pow(2,i);
    }
    return res;
}
