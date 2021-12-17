//Лабораторная 7, задача 1.1. Выполнена: Подвальников А.С.
/*Необходимо разработать программу для перевода чисел из
семеричной в двенадцатеричную систему счисления.Выполнить решение
задачи с помощью массивов.*/
#include <iostream>
#include <cmath>
#include<string>

void system12(int num,int size){
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
    for (int i = 0; i < size; i++)
        std::cout << str[i];
}

int main()
{
    int num;
    std::cout << "Enter the num(digits 7,8,9 are absent in the septenary numeral system): " << std::endl;
    std::cin >> num;
    int temp_num = num;
    int size1 = 1;
    while (temp_num >= 10){
        temp_num /= 10;
        size1++;
    }
    system12(num,size1);
    return 0;
}