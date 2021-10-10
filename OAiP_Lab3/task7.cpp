//Лабораторная 3, задача 7. Выполнена: Подвальников А.С.
/*.Найти двухзначное число, обладающее тем свойством, что куб
суммы его цифр равен квадрату самого числа.*/

#include <iostream>
#include <cmath>

int main()
{
    int number = 10;
    int first_digit;
    int second_digit;
    do
    {
        number++;
        first_digit = number / 10;
        second_digit = number % 10;
    }
    while (number <= 99 && pow((first_digit + second_digit ),3) != pow(number,2));
        std::cout << "This number is " << number;
    return 0;
}