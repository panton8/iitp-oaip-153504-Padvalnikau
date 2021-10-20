//Лабораторная 3, задача 4.2 Выполнена: Подвальников А.С.
/*Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.2 Без использования цикла.*/

#include <iostream>
#include <cmath>

int sum (int number)
{
    if (number == 0)
        return 0;
    return (number % 2 == 0) ? number + sum(number - 2) :  sum(number-1);
}

int main()
{
    double n;
    while(true)
    {
        std::cout << "Enter amount of numbers: " << std::endl;
        std::cin >> n;
        if(std::cin.fail() || n < 0.0 || n > 9223372036854775807.0 || n!= round(n))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    std::cout << "sum of n terms = " << sum(n);
    return 0;
}