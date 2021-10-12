//Лабораторная 3, задача 4.2 Выполнена: Подвальников А.С.
/*Вычислить сумму четных чисел на промежутке от 1 до числа,
введенного пользователем:
4.2 Без использования цикла.*/

#include <iostream>

void numbers_for_sum(int n)
{
    int sum = 0;
    while (n >= 1)
    {
        n % 2 == 0 ? sum += n : sum += 0;
        n--;
    }
    std::cout <<"Sum of n terms = " << sum;
}
int main()
{
    numbers_for_sum(15);
    return 0;
}