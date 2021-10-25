//Лабораторная 4, задача 2(1). Выполнена: Подвальников А.С.
/*Инициализировать при объявлении статический двумерный массив
целых чисел размером NxM.Определить количество положительных
элементов,расположенных ниже побочной диагонали */

#include <iostream>
#include <cmath>

int main()
{
    int numbers = 0,i,j;
    int N = 0,M = 0;
    std::cout << "Enter size(N and M) of array: " << std::endl;
    while(true) {
        std::cin >> N >> M;
        if (std::cin.fail() || N != (long long) N || N != round(N) || M != (long long) M || M != round(M)) {
            std::cout << "Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000, '\n');
            continue;
        }
        break;
    }
    int arr [N][M];
    std::cout << "Enter terms of massive: " << std::endl;
    for(i = 0; i < N ; i++)
    {
        for(j = 0; j < M ; j++) {
            while(true)
            {
                std::cin >> arr[i][j];
                if(std::cin.fail() ||  i != (long long)i || i!= round(i) || j != (long long)j || j!= round(j))
                {
                    std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(32000,'\n');
                    continue;
                }
                break;
            }
        }
    }
    for(i = 0; i < N ; i++)
    {
        for(j = 0; j < M ; j++)
        {
            std::cout << arr[i][j] << " ";
            if (j == M - 1)
                std::cout << std::endl;
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (i + j > M - 1)
                if(arr[i][j]>0)
                    numbers++;
            }
        }
    std::cout << "Number of positive numbers: " << numbers;
    return 0;
}