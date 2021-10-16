//Лабораторная 3, задача 4.1. Выполнена: Подвальников А.С.
/*Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.1 С использованием цикла.*/

#include <iostream>

int main()
{
    int n;
    std::cout << "Enter amount of numbers: " << std::endl;
    if (std::cin >> n){
    }
    else
    {
        std::cout << "Incorrect type of variable";
        return -1;
    }
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i % 2 == 0 ? i : 0;
    }
    std::cout << "Sum of n terms = " << sum;
    return 0;
}