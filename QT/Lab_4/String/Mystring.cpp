#include "Mystring.h"

MyString::MyString()
{
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

MyString::MyString(const char* cs, const size_t& n)
{
    unsigned i;

    for (i = 0; cs[i] != '\0'; i++);

    length = n + 1;

    str = new char[length];

    for (i = 0; i < (length - 1) && i < n; i++) {
        str[i] = cs[i];
    }
    str[n] = '\0';
}

MyString::MyString(const char* str)
{

    length = Mystrlen(str);


    this->str = new char[length + 1];


    for (int i = 0; i < length; i++)
    {
        this->str[i] = str[i];
    }


    this->str[length] = '\0';

}

MyString::MyString(const MyString& other)
{
    length = Mystrlen(other.str);
    this->str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        this->str[i] = other.str[i];
    }

    this->str[length] = '\0';
}

MyString::MyString(MyString&& other)
{
    this->length = other.length;
    this->str = other.str;
    other.str = nullptr;
}

MyString::MyString(const MyString& s, const size_t& pos, const size_t& n)
{
    unsigned i, j;

    str = new char[n + 1];

    length = n + 1;

    for (i = pos, j = 0; i < (pos + n); i++, j++) {

        str[j] = s.str[i];
    }
    str[n] = '\0';
}

MyString::MyString(const size_t& n, const char& c)
{
    unsigned i;

    length = n + 1;

    str = new char[length];

    for (i = 0; i < n; i++) {

        str[i] = c;
    }
    str[n] = '\0';
}

MyString::~MyString()
{
    delete[] this->str;
}


MyString& MyString::operator =(const MyString& other)
{

    if (this->str != nullptr)
    {
        delete[] str;
    }

    length = Mystrlen(other.str);
    this->str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        this->str[i] = other.str[i];
    }

    this->str[length] = '\0';

    return *this;

}

MyString MyString::operator+(const MyString& other)
{
    MyString newStr;


    int thisLength = Mystrlen(this->str);
    int otherLength = Mystrlen(other.str);

    newStr.length = thisLength + otherLength;


    newStr.str = new char[thisLength + otherLength + 1];


    int i = 0;
    for (; i < thisLength; i++)
    {
        newStr.str[i] = this->str[i];
    }

    for (int j = 0; j < otherLength; j++, i++)
    {
        newStr.str[i] = other.str[j];
    }

    newStr.str[thisLength + otherLength] = '\0';


    return newStr;
}



void MyString::Print()
{
    std::cout << str;
}


int MyString::Length()
{
    return length;
}


bool MyString::operator ==(const MyString& other)
{
    if (this->length != other.length)
    {
        return false;
    }

    for (int i = 0; i < this->length; i++)
    {
        if (this->str[i] != other.str[i])
        {
            return false;
        }
    }
    return true;
}


bool MyString::operator !=(const MyString& other)
{
    return !(this->operator==(other));
}


char& MyString::operator [](int index)
{
    return this->str[index];
}


void MyString::clear() {
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

bool MyString::empty() {
    if (str[0] == '\0') {
        return true;
    }
    return false;

}


MyString& MyString::operator+=(const char& c)
{
    unsigned i, k, size = length + 1;
    char* str1 = new char[size+1];

    for (i = 0; i < (length); i++) {
        str1[i] = str[i];
    }

    delete[] str;

    str = new char[size+1];
    length = size;

    for (k = 0; k < (size - 1); k++) {
        str[k] = str1[k];
    }

    str[size - 1] = c;
    str[size] = '\0';

    return *this;
}

MyString& MyString::operator+=(const char* cs)
{
    unsigned j, k, l;

    char* str1 = new char[length + Mystrlen(cs)+1];

    for (l = 0; l < length ; l++) {
        str1[l] = str[l];
    }

    for (j = 0; j <= Mystrlen(cs); j++)
    {
        str1[length + j ] = cs[j];
    }
    delete[] str;

    str = new char[length + Mystrlen(cs)+1];

    for (k = 0; k < (length + Mystrlen(cs)+1); k++) {
        str[k] = str1[k];
    }
    length += Mystrlen(cs);
    return *this;
}
MyString& MyString::operator+=(const MyString& s)
{
    int size = s.length + length;
    unsigned i, j, k;

    char* str1 = new char[size+1];

    for (i = 0; i < length; i++) {
        str1[i] = str[i];
    }
    for (j = 0; j < s.length; j++)
    {
        str1[j + length] = s.str[j];
    }

    delete[] str;
    length = size;

    str = new char[length+1];

    for (k = 0; k < length + 1; k++) {
        str[k] = str1[k];
    }
    return *this;
}


MyString& MyString::append(const char* cs)
{
    *this+=cs;

    return *this;
}

MyString& MyString::append(const MyString& s)
{
    MyString str1;
    str1 += s;

    *this = str;

    return *this;
}

int MyString::compare(const MyString& s) const
{
    unsigned i, j;
    int compare;

    bool less = 1, greater = 1, equal=1;

    if (length != s.length) {
        equal = 0;
    }

    else {
        for (i = 0; i < s.length; i++)
        {
            if (str[i] != s.str[i])
                equal = 0;
        }
    }

    for (i = 0, j = 0; j < s.length; i++, j++)
    {
        if (str[i] >= s.str[j])
            less = 0;
    }
    if (less || equal)
        greater = 0;

    if (less)
        compare = -1;

    if (greater)
        compare = 1;
    if (equal)
        compare = 0;
    return compare;
}

MyString& MyString::insert(const size_t& pos, const char* cs)
{
    MyString tmpStr(cs);
    MyString str1(str);

    *this = str1.insert(pos, tmpStr);

    return *this;
}

MyString& MyString::insert(const size_t& pos, const MyString& s)
{
    if (pos > length) {
        throw "index out of range!";
    }

    MyString str1(str);
    unsigned i, j;

    length = s.length + str1.length ;

    delete[] str;

    str = new char[length + 1];

    for (i = 0; i < pos; i++) {
        str[i] = str1.str[i];
    }
    for (i = pos, j = 0; j < s.length ; i++, j++){
        str[i] = s.str[j];
    }

    for (i = s.length + pos, j = pos; i < length; i++, j++) {
        str[i] = str1.str[j];
    }

    str[length] = '\0';

    return *this;
}

MyString& MyString::insert(const size_t& pos, const char* cs, const size_t& n)
{
    MyString tmpStr(cs, n);
    MyString str1(str);

    *this = str1.insert(pos, tmpStr);

    return *this;
}

MyString& MyString::insert(const size_t& pos1, const MyString& s, const size_t& pos2, const size_t& n)
{
    MyString tmpStr(s, pos2, n);
    MyString str1(str);

    *this = str1.insert(pos1, tmpStr);

    return *this;
}

MyString& MyString::insert(const size_t& pos, const size_t& n, const char& c)
{
    MyString tmpStr(n, c);
    MyString str1(str);

    *this = str1.insert(pos, tmpStr);

    return *this;
}



MyString& MyString::erase(const size_t& pos, const size_t& n)
{


    unsigned i, j;

    MyString str1(str);
    length = str1.length - n;

    delete[] str;

    str = new char[length+1];

    for (i = 0; i < pos; i++) {

        str[i] = str1.str[i];
    }
    for (i = pos, j = pos + n; j < str1.length; i++, j++) {
        str[i] = str1.str[j];
    }
    str[length] = '\0';
    return *this;
}

MyString& MyString::erase(const size_t& pos) {
    return erase(pos, length - pos);
}


const char* MyString::c_str() const
{
    char* cstring = new char[length + 1];

    for (int i = 0; i < length; i++) {
        cstring[i] = str[i];
    }
    cstring[length] = '\0';

    return cstring;
}


const char& MyString::at(const size_t& pos) const
{
    if (pos > length) {
        throw  "index out of range!";
    }
    return str[pos];
}

char& MyString::at(const size_t& pos)
{
    if (pos > length)
        throw "index out of range!";
    return str[pos];
}


void MyString::push_back(const char& c)
{
    this->operator+=(c);
}


MyString MyString::substr(const size_t& pos, const size_t& n)
{
    MyString tmpStr;
    unsigned i, j;
    if (pos > length)
    {
        throw "index out of range";
        return tmpStr;
    }

    if (pos == length) {
        return tmpStr;
    }

    else
    {
        for (i = pos, j = 0; (j < n && str[i] != '\0'); i++, j++)
        {
            tmpStr.expandString(1);
            tmpStr.str[j] = str[i];
        }
    }
    tmpStr.str[j] = '\0';
    return tmpStr;
}


MyString& MyString::replace(const size_t& pos, const size_t& n, const MyString& s)
{

    if (pos + n > length) {
        throw "position out of range";
    }
    MyString tmpStr(str);

    unsigned i;

    tmpStr.erase(pos, n);
    tmpStr.insert(pos, s);

    length = tmpStr.length;

    delete[] str;

    str = new char[length+1];
    for (i = 0; i < length; i++) {
        str[i] = tmpStr.str[i];
    }
    str[length] = '\0';

    return *this;
}

MyString& MyString::replace(const size_t& pos1, const size_t& n1, const MyString& s, const size_t& pos2, const size_t& n2)
{
    unsigned i;

    MyString tmpStr(str);
    MyString str1(s, pos2, n2);

    tmpStr.erase(pos1, n1);
    tmpStr.insert(pos1, str1);

    length = tmpStr.length;

    delete[] str;

    str = new char[length];

    for (i = 0; i < length; i++) {
        str[i] = tmpStr.str[i];
    }
    return *this;
}
MyString &MyString::replace(const size_t& pos, const size_t& n1, const char* cs, const size_t& n2)
{
    unsigned i;

    MyString tmpStr(str);
    MyString str1(cs, n2);

    tmpStr.erase(pos, n1);
    tmpStr.insert(pos, str1);

    length = tmpStr.length;

    delete[] str;

    str = new char[length];

    for (i = 0; i < length; i++){

        str[i] = tmpStr.str[i];
}
return *this;
}

void MyString::pop_back() {
    if (length > 0) {
        erase(length - 1);
    }
    return;
}

int MyString::find (const MyString& other, size_t start) const {
    int exist = -1;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == other.str[0]) {
            exist = i;
            for (int j = i,  k=0 ; j <length && k<other.length ; j++, k++)
            {
                if (str[j] != other.str[k]) {
                    exist = -1;
                    break;
                }

            }
        }
    }
    return exist;

}


void MyString::resize(size_t newSize) {
    /*char* newStr = new char[newSize+1];
    for (int  i = 0; i < newSize; i++)
    {
        newStr[i] = str[i];
    }


    delete[] str;

    char* str = new char[newSize + 1];
    for (int i = 0; i < newSize; i++)
    {
        str[i] = newStr[i];
    }

    str[newSize] = '\0';
    delete[] newStr;*/
    if (newSize < length) {
        erase(newSize);
    }
    else {
        return;
    }

}

void MyString::resize(size_t newSize, const char& elem) {
    if (newSize > length){
        unsigned copyLength = length;
        for (int i = 0; i < newSize-copyLength+1; i++)
        {
            this->operator+=(elem);
        }
    }
    else {
        resize(newSize);
    }
}


void MyString::expandString(const size_t& n)
{
    unsigned exp = n + length;
    char* temp = new char[exp + 1];

    Mymemset(temp, 0, exp + 1);

    temp[exp] = '\0';

    for (unsigned i = 0; i < length; i++) {
        temp[i] = str[i];
    }

    clear();
    length = exp;

    str = new char[length + 1];
    Mymemset(str, 0, length + 1);

    str[length] = '\0';

    for (unsigned i = 0; temp[i] != '\0'; i++) {
        str[i] = temp[i];
    }
    delete[] temp;
    temp = NULL;
}

void* MyString::Mymemset(void* dest, int val, size_t len)
{
    char* ptr = (char*)dest;
    while (len-- > 0)
        *ptr++ = val;
    return dest;
}

void* MyString::Mymemcpy(void* s1, const void* s2, size_t n)
{
    char* d = (char*)s1;
    const char* s = (char*)s2;

    while (n--) {
        *d++ = *s++;
    }
    return s1;
}

int MyString::Mymemcmp(const void* str1, const void* str2, size_t count)
{
    const char* s1 = (char*)str1;
    const char* s2 = (char*)str2;

    while (count-- > 0)
    {
        if (*s1++ != *s2++)
            return s1[-1] < s2[-1] ? -1 : 1;
    }
    return 0;
}

void* MyString::Mymemmove(void* dest, const void* src, size_t len)
{
    char* d = (char*)dest;
    const char* s = (char*)src;
    if (d < s)
        while (len--)
            *d++ = *s++;
    else
    {
        char* lasts = (char*)s + (len - 1);
        char* lastd = d + (len - 1);
        while (len--)
            *lastd-- = *lasts--;
    }
    return dest;
}

int MyString::Mystrncmp(const char* str1, const char* str2, size_t num)
{
    /* assert(str1);
     assert(str2);*/
     // В следующем во время функции
     // Состояние первого цикла: - Num, если по сравнению с предыдущими символами NU, выездной петли
     // Состояние второго цикла: * STR1 == * STR2, если два символа равны, они выходят на циклы.
    while (--num && *str1 == *str2)
    {
        if (*str1 == '\0') // * str1, если строка указывает на строку, чтобы выйти из цикла
            return 1;
        else {}
        str1++; // str1 указатель self-add 1, указывая на следующий символ
        str2++; // Указатель Str2 Self-Add 1, указывая на следующий символ
    }

    return*str1 - *str2; // вернуть результат сравнения
}

char* MyString::Mystrncat(char* dest, char const* src, size_t  n)
{
    /* assert(dest);
     assert(src);*/

    char* temp = dest;
    while (*dest)
    {
        dest++;
    }
    while (n-- && *src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return temp;
}

char* MyString::Mystrncpy(char* dest, char* src, size_t num)
{
    char* ret = dest;
    //assert(dest && src);
    while (num--)
    {
        *ret++ = *src++;
    }
    *ret = 0;
    return ret;
    
    if (dest == NULL) {
        return NULL;
    }

    // take a pointer pointing to the beginning of the destination string
    char* ptr = dest;

    // copy first `num` characters of C-string pointed by source
    // into the array pointed by destination
    while (*src && num--)
    {
        *dest = *src;
        dest++;
        src++;
    }

    // null terminate destination string
    *dest = '\0';

    // the destination is returned by standard `strncpy()`
    return ptr;
}

size_t MyString::Mystrlen(const char* s) {
    size_t counter = 0;
    while (true)
    {
        if (s[counter] == '\0') {
            break;
        }
        counter++;
    }
    return counter;

}

char* MyString::Mystrcpy(char* dest, const char* src) {\
    int i;
 for(i = 0; src[i] != '\0'; i++)
     dest[i] = src[i];
 dest[i] = '\0';
 return dest;
}
