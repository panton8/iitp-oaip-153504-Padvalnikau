//Лабораторная 3, задача 4.1. Выполнена: Подвальников А.С.
/*Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.1 С использованием цикла.*/

#include <iostream>

int main()
{
    int n;
    std::cout << "Enter amount of numbers: " << std::endl;
    std::cin >> n;
    if (!std::cin)
    {
        std::cout << "Variable input error" << std::endl;
        return -1;
    }
    int sum = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        i % 2 == 0 ? sum += i : sum +=0;
    }
    std::cout << "Sum of n terms = " << sum;
    return 0;
}