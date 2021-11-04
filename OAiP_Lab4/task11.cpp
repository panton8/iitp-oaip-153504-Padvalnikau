//Лабораторная 4, задача 11. Выполнена: Подвальников А.С.
/*Дан трёхмерный динамический массив размером n^3 целых
неотрицательных чисел. Необходимо определить диагональ с наибольшей
суммой чисел. Для обхода диагоналей нельзя использовать вложенные
циклы.*/

#include <iostream>
#include <time.h>
#include <iomanip>

int main()
{
    srand(time(nullptr));
   int N = 0;
   std::cin >> N;
    long long ***arr = new long long** [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new long long* [N];
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = new long long[N];
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int p = 0; p < N; p++)
                arr[i][j][p] = 1 + rand() % 20;
    int d1 = 0,d2 = 0,d3 = 0,d4 = 0;
    for (int i = 0, j = N - i - 1; i < N; i++, j--)
    {
        d1 += arr[i][i][i];
        d2 += arr[j][i][i];
        d3 += arr[i][j][i];
        d4 += arr[j][j][i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int p = 0; p < N; p++)
            {
                std::cout << std::setw(2) << arr[i][j][p] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    long long maxSum = std::max(d1, std::max(d2, std::max(d3, d4)));

    std::cout << "Max sum of diagonal: " << maxSum << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}