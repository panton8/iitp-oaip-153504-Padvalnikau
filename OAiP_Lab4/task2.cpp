//Лабораторная 4, задача 2. Выполнена: Подвальников А.С.
/*Инициализировать при объявлении статический двумерный массив
целых чисел размером NxM.Определить количество положительных
элементов,расположенных ниже побочной диагонали */

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int numbers = 0,i,j;
    const int N = 4,M = 3;
    int arr[N][M];
    std::cout << "Enter terms of massive: " << std::endl;
    for(i = 0; i < N ; i++)
    {
        for(j = 0; j < M ; j++) {
            while(true)
            {
                std::cin >> arr[i][j];
                if(std::cin.fail() ||  i != (int)i || i!= round(i) || j != (int)j || j!= round(j))
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
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (i + j > M - 1 )
                if(arr[i][j]>0)
                    numbers++;
            }
        }
    std::cout << "Number of positive numbers: " << numbers;
    return 0;
}