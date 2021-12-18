#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool negative;

void system3(int a, string& Digit) {
    if (a / 3)
        system3(a / 3, Digit);
    string temp = to_string(a % 3);
    Digit.push_back(temp[0]);
}
string newSystem3(string digit3, string& Digit, int i) {
    string temp3; temp3[0] = digit3[i];
    short a;
    if (atoi(temp3.c_str()) < 1) {
        string temp = to_string(atoi(temp3.c_str()) + 3);
        Digit[i] = temp[0];
        if (i == 0) {
            string newDigit;
            newDigit.resize(Digit.length() + 1);
            newDigit[0] = '2';
            for (short j = 0, k = 1; j < Digit.length(); ++j, ++k) newDigit[k] = Digit[j];
            return newDigit;
        }
        temp[0] = digit3[i - 1];
        a = atoi(temp.c_str()) - 1;
        if (a >= 0) {
            temp.erase(0, 1);
            string y = to_string(a);
            temp.push_back(y[0]);
            digit3[i - 1] = temp[0];
        }
        else {
            bool zero = 0;
            a += 3;
            temp.erase(0, 1);
            string y = to_string(a);
            temp.push_back(y[0]);
            if (digit3[i - 1] == '0') zero = 1;
            digit3[i - 1] = temp[0];
            if (zero) {
                temp[0] = digit3[i - 2];
                a = atoi(temp.c_str()) - 1;
                temp = to_string(a);
                digit3[i - 2] = temp[0];
            }
        }
    }
    else Digit[i] = digit3[i];
    if (i - 1 == 0 && digit3[i - 1] == '0') {
        if(negative)
            putchar('-');
        Digit.erase(0, 1);
        return Digit;
    }
    if(i == 0) {
        if (negative)
            putchar('-');
        return Digit;
    }
    return newSystem3(digit3, Digit, --i);
}

//////////
/////////

std::string arabicToRoman(int n) {

    std::string rom_str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while(n - values[i] >= 0)
        {
            result += rom_str[i];
            n -= values[i];
        }
    }
    return result;
}

 //////////
 /////////

std::string reverseCode(std::string straight_code){
    std::string reverse_code;
    int str_size = 0;
    for(int i = 0; straight_code[i] != '\0'; i++)
        str_size++;
    for(int i = 0; i < str_size; i++)
    {
        if(i == 0)
            reverse_code += straight_code[0];
        if(straight_code[0] == '0' && i > 0)
            reverse_code += straight_code[i];
        else
        if( i > 0 && straight_code[i] == '0')
            reverse_code += '1';
        else if( i > 0 && straight_code[i] == '1')
            reverse_code += '0';
    }
    return reverse_code;
}

//////////
/////////

string system12(long long num,int size){
    int num1 = 0;
    for (int i = 0; i < size; i++)
    {
        num1 += (num % 10) * pow(7, i);
        num /= 10;
    }
    int rem;
    char* str = new char[size];
    for (int i = size - 1; i > 0; i--)
    {
        rem = num1 % 12;
        num1 = (num1 - rem) / 12;
        if (rem == 10)
            str[i] = 'a';
        else {
            str[i] = (char) (rem + 48);
        }
    }
    if (num1 == 10)
        str[0] = 'a';
    else if (num1 == 0)
        str[0] = ' ';
    else {
        str[0] = (char) (num1 + 48);
    }
    for(int i = 0; i < size; i++){
        if(str[i] == ';')
            str[i] = 'b';
        if(str[1] == '0')
            str[1] = ' ';
    }
   return str;
}

///////////
//////////

std::string reverse(std::string str, int size) {
    if (size == -1)
        return "";
    else
    {
        char a;
        a = str[size];
        return a + reverse(str, size - 1);
    }
}

std::string additionalCode(std::string str){
    std::string additional_code;
    int a = 0;
    for(int i = 0; i < 8; i++) {
        if(str[0] == '-'){
            a = 8;
        }
        if(i == 0 && a == 8)
        {
            additional_code += '1';
        }
        if(a == 8 && i > 0){
            if(str[i] == '1') additional_code += '0';
            if(str[i] == '0') additional_code += '1';
        }
        else if (!a){
            if (str[i] == '0')
                additional_code += '0';
            else if (str[i] == '1')
                additional_code += '1';
        }
    }
    int size = 0;
    for(int i = 0; additional_code[i] != '\0';i++)
        size++;
    additional_code = reverse(additional_code,size);
    for(int i = 0; i < 8; i++){
        if(a == 8 &&  i > size-1 ){
            additional_code += '1';
        }
        if( !a && i > size-1)
            additional_code += '0';
    }
    additional_code = reverse(additional_code,8);
    for(int i = 7; i >= 0; i--){
        if(a == 8){
            if(additional_code[i] == '0') {
                additional_code[i] = '1';
                break;
            }
            if(additional_code[i] == '1')
                additional_code[i] = '0';
        }
    }
    return additional_code;
}

std::string sumInAddCode(std::string str1,std::string str2){
    std::string  add_sum;
    for(int i = 7; i >= 0; i--){
        if (str1[i] != str2[i]){
            add_sum += '1';
        }
        else if(str1[i] == str2[i] && str1[i] == '0') {
            add_sum += '0';
        }
        else if(str1[i] == str2[i] && str1[i] == '1') {
            if(str1[i+1] != str2[i+1] && (str1[i+1] == '1' || str1[i+1] == '0')){
                add_sum += '0';
                if(str1[i-1] != '1') str1[i - 1] = '1';
                else if(str1[i-1] == '1') str2[i-1] = '1';
            }
            else{
                add_sum += "011";
                i -= 2;
            }

        }
    }
    for(int i =0; i < 8; i++){
        if(add_sum[i] == ' ')
            add_sum.erase(i,1);
    }
    add_sum = reverse(add_sum,8);
    return add_sum;
}

//////////
/////////

int subtr(int x, int y) {
    while (y) {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}
int inc(int i) {
    int mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}
int diV(int n, int d) {
    int q = 0;
    while (n >= d) {
        int i = 0, temp_d = d;
        while (n >= (temp_d << 1)) {
            i = inc(i);
            temp_d <<= 1;
        }
        q |= 1 << i;
        n = subtr(n, temp_d);
    }
    return q;
}
int add(int x, int y) {
    while (y) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
int mult(int a, int b) {
    int result = 0;
    while (b) {
        if (b & 01) result = add(result, a);
        a <<= 1; b >>= 1;
    }
    return result;
}
int mod(int a, int b) {
    int r = diV(a, b);
    return subtr(a, mult(r, b));
}

/////////
////////

long long S(long long n){
    if(n == 0)
        return 0;
    return (n % 10) + S(n/10);
}

long long interesting(long long num){
    S(num);
    return (num+1)/10;
}

//////////
/////////

std::string Sum(std::string str1, std::string str2,int size) {
    std::string Sum;
    int new_digit = 0;
    int temp = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str1[i] == 'a')
            temp += 10;
        else if(str1[i] == 'b')
            temp += 11;
        else
            temp = str1[i] - '0';
        if (str2[i] == 'a')
            temp += 10;
        else if(str2[i] == 'b')
            temp += 11;
        else
            temp += str2[i] - '0';
        temp += new_digit;
        new_digit = 0;
        if (temp - 12 == 10) {
            Sum += 'a';
        }
        else if( temp - 12 == 11)
            Sum += 'b';
        else if (temp > 10) {
            new_digit += 1;
            Sum += (char)temp - 12 + '0';
        }
        else if (temp < 10) {
            Sum += (char)temp + '0';
        }
        temp = 0;
    }
    Sum = reverse(Sum,size);
    return Sum;
}
std::string diff(std::string str1, std::string str2, int size) {
    std::string diff = "";
    int cu = 0;
    int temp = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str1[i] == 'a')
            temp += 10;
        else if(str1[i] == 'b')
            temp += 11;
        else
            temp = str1[i] - '0';
        if (str2[i] == 'a')
            temp -= 10;
        else if(str2[i] == 'b')
            temp -= 11;
        else
            temp -= str2[i] - '0';
        temp += cu;
        cu = 0;
        if (str1[i] < 0) {
            temp += 12;
            cu -= 1;
        }
        diff += (temp + '0');
        temp = 0;
    }
    for(int i = 0; i < size; i++){
        if(diff[i] == '/') {
            diff.replace(i,1,"bb");
        }
    }
    diff = reverse(diff,size);
    return diff;
}
TEST(task9, test1) {
int digit = 6;
string Digit;
system3(digit,Digit);
string digit3 = Digit;
EXPECT_EQ("13",newSystem3(digit3, Digit, Digit.length() - 1));
EXPECT_TRUE(true);
}

TEST(task9, test2) {
int digit = 7;
string Digit;
system3(digit,Digit);
string digit3 = Digit;
EXPECT_EQ("21",newSystem3(digit3, Digit, Digit.length() - 1));
EXPECT_TRUE(true);}

TEST(task9, test3) {
int digit = 22;
string Digit;
system3(digit,Digit);
string digit3 = Digit;
EXPECT_EQ("211",newSystem3(digit3, Digit, Digit.length() - 1));
EXPECT_TRUE(true);
}

TEST(task9,test4){
int digit = 2000000000;
string Digit;
system3(digit,Digit);
string digit3 = Digit;
EXPECT_EQ("11233323323111313232",newSystem3(digit3, Digit, Digit.length() - 1));
EXPECT_TRUE(true);
}

TEST(task9,test5){
    int digit = 9651;
    string Digit;
    system3(digit,Digit);
    string digit3 = Digit;
    EXPECT_EQ("33312333",newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task9,test6){
    int digit = 1;
    string Digit;
    system3(digit,Digit);
    string digit3 = Digit;
    EXPECT_EQ("1",newSystem3(digit3, Digit, Digit.length() - 1));
    EXPECT_TRUE(true);
}

TEST(task5, test1) {
EXPECT_EQ("X",arabicToRoman(10));
EXPECT_TRUE(true);
}

TEST(task5, test2) {
EXPECT_EQ("CMXCIX",arabicToRoman(999));
EXPECT_TRUE(true);
}

TEST(task5, test3) {
EXPECT_EQ("M",arabicToRoman(1000));
EXPECT_TRUE(true);
}

TEST(task5, test4) {
EXPECT_EQ("I",arabicToRoman(1));
EXPECT_TRUE(true);
}

TEST(task5, test5) {
EXPECT_EQ("CCXXXVII",arabicToRoman(237));
EXPECT_TRUE(true);
}

TEST(task5, test6) {
EXPECT_EQ("DCLI",arabicToRoman(651));
EXPECT_TRUE(true);
}

TEST(task2, test1) {
EXPECT_EQ("11101101", reverseCode("10010010"));
EXPECT_TRUE(true);
}

TEST(task2, test2) {
EXPECT_EQ("0101001",  reverseCode("0101001"));
EXPECT_TRUE(true);
}

TEST(task2, test3) {
EXPECT_EQ("10101010",  reverseCode("11010101"));
EXPECT_TRUE(true);
}

TEST(task2, test4) {
EXPECT_EQ("10000000",  reverseCode("11111111"));
EXPECT_TRUE(true);
}

TEST(task2, test5) {
EXPECT_EQ("01111111",  reverseCode("01111111"));
EXPECT_TRUE(true);
}

TEST(task1, test1) {
    EXPECT_EQ(" 8", system12(11,2));
    EXPECT_TRUE(true);
}

TEST(task1, test2) {
    EXPECT_EQ(" 1241a", system12(132163,6));
    EXPECT_TRUE(true);
}

TEST(task1, test3) {
    EXPECT_EQ("  b2031", system12(1653121,7));
    EXPECT_TRUE(true);
}

TEST(task1, test4) {
    EXPECT_EQ(" 112a3", system12(123456,6));
    EXPECT_TRUE(true);
}

TEST(task7, test1) {
int num = 89, check_div1 = 3;
EXPECT_EQ(2, mod(num,check_div1));
EXPECT_TRUE(true);
}

TEST(task7, test2) {
int num = 126, check_div1 = 3;
EXPECT_EQ(0, mod(num,check_div1));
EXPECT_TRUE(true);
}

TEST(task7, test3) {
int num = 512, check_div1 = 37;
EXPECT_EQ(31, mod(num,check_div1));
EXPECT_TRUE(true);
}

TEST(task7, test4) {
int num = 222, check_div1 = 37;
EXPECT_EQ(0, mod(num,check_div1));
EXPECT_TRUE(true);
}

TEST(task7, test5) {
int num = 317, check_div1 = 89;
EXPECT_EQ(50, mod(num,check_div1));
EXPECT_TRUE(true);
}

TEST(task7, test6) {
int num = 1246, check_div1 = 89;
EXPECT_EQ(0, mod(num,check_div1));
EXPECT_TRUE(true);
}

TEST(task6,test1){
int num = 1;
EXPECT_EQ(0, interesting(num));
EXPECT_TRUE(true);
}

TEST(task6,test2){
int num = 9;
EXPECT_EQ(1, interesting(num));
EXPECT_TRUE(true);
}

TEST(task6,test3){
int num = 10;
EXPECT_EQ(1, interesting(num));
EXPECT_TRUE(true);
}

TEST(task6,test4){
int num = 34;
EXPECT_EQ(3, interesting(num));
EXPECT_TRUE(true);
}

TEST(task6,test5){
int num = 880055535;
EXPECT_EQ(88005553, interesting(num));
EXPECT_TRUE(true);
}

TEST(task6,test6){
int num = 619;
EXPECT_EQ(62, interesting(num));
EXPECT_TRUE(true);
}


TEST(task4,test1){
EXPECT_EQ("bb25", diff("125","200",3));
EXPECT_TRUE(true);
}

TEST(task4,test2){
EXPECT_EQ("bb42", diff("289","347",3));
EXPECT_TRUE(true);
}