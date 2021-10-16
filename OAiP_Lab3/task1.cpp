//Лабораторная 3, задача 1. Выполнена: Подвальников А.С.
/*(использовать while) Вычислить сумму,где a и b определены по формуле.*/

#include <iostream>
#include <cmath>

int main()
{
    int i = 1;
    int sum = 0;
    int a,b;
    while(i <= 30)
    {
        a = i % 2 == 1 ? i : i/2;
        b = i % 2 == 1 ? i*i : i*i*i;
        sum += pow(a-b,2);
        i++;
    }
    std::cout << "Sum of 30 terms = " << sum;
    return 0;
}