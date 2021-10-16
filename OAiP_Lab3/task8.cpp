//Лабораторная 3, задача 8. Выполнена: Подвальников А.С.
/*Числа Армстронга (названные в честь Майкла Ф. Армстронга
(Michael F. Armstrong)), их также называют самовлюбленными числами и
совершенными цифровыми инвариантами, – это числа, равные сумме своих
цифр, возведенных в степень, равную количеству цифр. Например,
наименьшее число Армстронга – 153, которое равно 1^3 + 5^3 + 3^3 . Напишите
программу, которая выводит все числа армстронга меньше 10^6.*/

#include <iostream>
#include <cmath>

int main()
{
    int number_of_digits;
    std::cout << "Armstrong numbers: ";
    for (int i = 153; i < 1000000; i++)
    {
        int sixth_digit = i / 100000;
        int fifth_digit = (i / 10000) % 10;
        int fourth_digit = (i / 1000) % 10;
        int third_digit = (i / 100) % 10;
        int second_digit = (i / 10) % 10;
        int first_digit = i % 10;
        if (sixth_digit)
            number_of_digits = 6;
        if (fifth_digit && !sixth_digit)
            number_of_digits = 5;
        if (fourth_digit && !fifth_digit)
            number_of_digits = 4;
        if (third_digit && !fourth_digit)
            number_of_digits = 3;
        int a1 = (int) pow(sixth_digit, number_of_digits);
        int a2 = (int) pow(fifth_digit, number_of_digits);
        int a3 = (int) pow(fourth_digit, number_of_digits);
        int a4 = (int) pow(third_digit, number_of_digits);
        int a5 = (int) pow(second_digit, number_of_digits);
        int a6 = (int) pow(first_digit, number_of_digits);
        if ((a1 + a2 + a3 + a4 + a5 + a6 == i))
            std::cout << i << "; ";
    }
    return 0;
}