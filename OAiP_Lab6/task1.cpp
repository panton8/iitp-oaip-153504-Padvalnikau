//Лабораторная 6, задача 1. Выполнена: Подвальников А.С.
/*В строке, состоящей из групп нулей и единиц, разделенных
пробелами, найти количество групп с пятью цифрами.*/

#include <iostream>
#include <cstring>

char inputCheck(char str[80]){
    int a = 0;
    gets(str);
    for(int i = 0;i < strlen(str); i++)
    {
        if( (str[i] == ' ') || (str[i] == '1') || (str[i] == '0'))
            a++;
    }
    while(true) {
        if( a != strlen(str))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            inputCheck(str);
            continue;
        }
        break;
    }
    return *str;
}

int main() {
    const int N = 80;
    int common_count = 0;
    int local_count = 0;
    char str[N];
    std::cout << "Full your array of chars with 1 and 0: " << std::endl;
    inputCheck(str);
    std::cout << str;
    int a = strlen(str);
    for(int i = 0;i < a;i++) {
        if(str[i] ==  '1' || str[i] =='0')
            local_count++;
        if(str[i] == ' ')
            local_count = 0;
        if(local_count == 5 && (str[i+1] == ' ' || i == a-1)) {
            common_count++;
            local_count = 0;
        }
    }
    std::cout << std::endl << "The number of groups: " << common_count;
    return 0;
}