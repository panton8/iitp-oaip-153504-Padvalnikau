//Лабораторная 3, задача 4.1. Выполнена: Подвальников А.С.
/*Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.1 С использованием цикла.*/

#include <iostream>
#include <cmath>

int main()
{
    double n;
    int sum = 0;
    while(true)
    {
        std::cout << "Enter number of terms(more then 3): " << std::endl;
        std::cin >> n;
        if(std::cin.fail() || n !=(long long)n || n!= round(n) || n < 1)
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    for (int i = 0; i <= n; i++)
    {
        sum += i % 2 == 0 ? i : 0;
    }
    std::cout << "Sum of n terms = " << sum;
    return 0;
}