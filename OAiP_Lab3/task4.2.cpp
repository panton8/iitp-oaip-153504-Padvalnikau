//Лабораторная 3, задача 4.2 Выполнена: Подвальников А.С.
/*Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.2 Без использования цикла.*/

#include <iostream>

int sum (int number)
{
    if (number == 0)
        return 0;
    return (number % 2 == 0) ? number + sum(number - 2) :  sum(number-1);
}

int main()
{
    int n;
    std::cout << "Enter amount of numbers: " << std::endl;
    if (std::cin >> n)
    {
        std::cout << "sum of n terms = " << sum(n);
    }
    else
    {
        std::cout << "Incorrect type of variable";
        return -1;
    }
    return 0;
}