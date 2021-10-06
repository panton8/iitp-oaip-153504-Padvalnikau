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
    int number = 153;
    int first_digit,second_digit,third_digit,fourth_digit,fifth_digit,sixth_digit,seventh_digit,number_of_digits;
    int a,b,c,d,e,f,g;
    do
    {
        first_digit = number / 1000000;
        second_digit = (number - (first_digit * 1000000)) / 100000;
        third_digit = (number - (first_digit * 1000000) - (second_digit * 100000)) / 10000;
        fourth_digit = (number - (first_digit * 1000000) - (second_digit * 100000) - (third_digit * 10000)) / 1000;
        fifth_digit = (number - (first_digit * 1000000) - (second_digit * 100000) - (third_digit * 10000) - (fourth_digit * 1000))/100;
        sixth_digit = (number - (first_digit * 1000000) - (second_digit * 100000) - (third_digit * 10000) - (fourth_digit * 1000) - (fifth_digit * 100))/10;
        seventh_digit = (number - (first_digit * 1000000) - (second_digit * 100000) - (third_digit * 10000) - (fourth_digit * 1000) - (fifth_digit * 100) - (sixth_digit*10));
        number++;
        if (first_digit)
            number_of_digits = 7;
        else if (!first_digit && second_digit)
            number_of_digits = 6;
        else if(!second_digit && third_digit)
            number_of_digits = 5;
        else if(!third_digit && fourth_digit)
            number_of_digits = 4;
        else if(!fourth_digit && fifth_digit)
            number_of_digits = 3;
        a = (int)pow(first_digit,number_of_digits);
        b = (int)pow(second_digit,number_of_digits);
        c =(int) pow(third_digit,number_of_digits) ;
        d = (int)pow (fourth_digit,number_of_digits);
        e = (int)pow(fifth_digit,number_of_digits);
        f = (int)pow(sixth_digit,number_of_digits) ;
        g = (int)pow(seventh_digit,number_of_digits);
        if(a + b + c + d + e + f + g == (number - 1))
            std::cout << number - 1 <<" - one of the Armstrong numbers" << std::endl;
    }
    while (number <= 999999);
    return 0;
}

