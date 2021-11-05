// Лабораторная работа 4, задача 10. Выполнена: Подвальников А.С.
/*Построить магический квадрат любого порядка, используя любой алгоритм.
Выделение памяти через функции языка С.*/
#include <iostream>
#include <iomanip>

int main()
{
    int** arr = (int**)calloc(4, sizeof(int*));
    for (int i = 0; i < 4; i++)
    {
        arr[i] = (int*)calloc(4, sizeof(int));
    }
    int sum = 1;
    for(int i = 0;i < 4; i++){
        for (int j = 0; j < 4; j++) {
            if(i == j || (i + j == 4 - 1))
                arr[i][j] = 0;
            else
            arr[i][j] = sum;
            sum++;
        }
    }
    sum = 16;
    for(int i = 0;i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(arr[i][j] == 0)
                arr[i][j] = sum;
            sum--;
        }
    }
    std::cout << "Magic square: " << std::endl;
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0; j < 4; j++)
            std::cout << std::setw(2)<< arr[i][j] << " ";
        std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}