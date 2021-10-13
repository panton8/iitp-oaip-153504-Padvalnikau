//Лабораторная 3, задача 9. Выполнена: Подвальников А.С.
/*Вычислить a0 - 2a1 + 4a2 - 8a3 + ... + 2^(n-1)*(-1)^(n-1)*an-1.
Входные данные таковы,что результат может быть вычислен безпереполнения.
Использование вещесввенной арифметики запрещено.*/

#include <iostream>
#include <time.h>

int main()
{
    int n;
    std::cout << "Enter amount of numbers: " <<std::endl;
    std::cin >> n;
    int k = 1;
    int sum = 0;
    int sign = 1;
    int array [n];
    srand(time(0));
    for(int i = 0; i < n ; i++)
        array[i] = 1 + rand() % 20;
    std::cout << "Your massive: " << std::endl;
    for (int i = 0; i < n ; i++)
        std::cout <<array[i] << "; ";
    for (int i = 0; i < n ; i++ )
    {
        sum += sign * k * array[i];
        k *= 2;
        sign *= -1;
    }
    std::cout << std::endl << "Sum of numbers in your massive: " << sum;
    return 0;
}