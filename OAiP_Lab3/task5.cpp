//Лабораторная 3, задача 5. Выполнена: Подвальников А.С.
/*Необходимо разложить функцию Y(x) из своего варианта в ряд
S(x), затем с помощью полученного ряда найти значение функции и сравнить
его со значением, вычисленным с помощью стандартных функций. программа
должна запросить у пользователя количество членов ряда (n), затем запросить
у пользователя количество чисел, от которых он хочет посчитать функцию,
затем пользователь вводит по одному числу (x от 0.1, до 1), программа считает
значение функции с помощью ряда и с помощью стандартных функций и
выводит оба значения*/

#include<iostream>
#include<cmath>

int main()
{
    double x;
    std::cout << "Enter x (from 0.1 to 1)" <<std::endl;
    if (std::cin >> x){
    }
    else
    {
        std::cout << "Incorrect type of variable";
        return -1;
    }
    if (x < 0.1 || x > 1)
    {
        std::cout << "Incorrect entered value";
        return -1;
    }
    double res = x;
    int n ;
    std::cout << "Enter number of terms(more then 3): " << std::endl;
    if (std::cin >> n){
    }
    else
    {
        std::cout << "Incorrect type of variable";
        return -1;
    }
    if (n < 3)
    {
        std::cout << "Incorrect entered value";
        return -1;
    }
    int sign = -1;
    int i;
    for(i = 3; i < n ; i += 2, sign = -sign)
    {
        res += sign * res * (x * x) / (i * (i - 1));
    }
    std::cout << "S(x) = " << res << std::endl;
    std::cout << "Y(x) = " << sin(x);
    return 0;
}