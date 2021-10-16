//Лабораторная 3, задача 7. Выполнена: Подвальников А.С.
/*.Найти двухзначное число, обладающее тем свойством, что куб
суммы его цифр равен квадрату самого числа.*/

#include <iostream>
#include <cmath>

int main()
{
    for (int i = 10;i < 100;i++ )
    {
        int first_digit = i / 10;
        int second_digit = i % 10;
        if((pow(first_digit + second_digit,3) ) == pow(i,2))
            std::cout << "This number is " << i;
    }
    return 0;
}