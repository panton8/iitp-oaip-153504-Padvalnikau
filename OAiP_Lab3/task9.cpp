//Лабораторная 3, задача 9. Выполнена: Подвальников А.С.
/*Вычислить a0 - 2a1 + 4a2 - 8a3 + ... + 2^(n-1)*(-1)^(n-1)*an-1.
Входные данные таковы,что результат может быть вычислен безпереполнения.
Использование вещесввенной арифметики запрещено.*/

#include <iostream>
#include <time.h>
#include <cmath>
int main()
{
    int M;
    long double n;
    while(true)
    {
        std::cout << "Enter amount of numbers: " << std::endl;
        std::cin >> n;
        if(std::cin.fail() || n != (long long )n || n < 1  || n != round(n))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    int k = 1;
    long long int sum = 0;
    int sign = 1;
    srand(time(NULL));
    std::cout << "Your random numbers: ";
    for (int i = 0; i < n ; i++ )
    {
        M = 1 + rand () % 20;
        sum += sign * k * M;
        k *= 2;
        sign *= -1;
        std::cout << M << "; ";
    }
    std::cout << std::endl << "Result of expression with your massive: " << sum;
    return 0;
}