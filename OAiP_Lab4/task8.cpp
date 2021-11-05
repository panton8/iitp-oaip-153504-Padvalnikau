//Лабораторная 4, задача 8. Выполнена: Подвальников А.С.
/*Заменить нулями все элементы, которые находятся в ячейках
между минимальным и максимальным элементами (не включая их).
Изначально все элементы в массиве различные. Если после данного действия
большая часть массива будет содержать нули, то удалить все нулевые
элементы из массива (c сохранением порядка следования остальных
элементов).*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

int main()
{
int N = 0;
srand(time(NULL));
std::cout << "Enter size of array: " << std::endl;
while(true)
{
    std::cin >> N ;
    if(std::cin.fail() || N < 1 || N != (int)(N) || N!= round (N)){
        std::cout << "Incorrect type of variable! Please,enter your value again: " << std::endl;
    std::cin.clear();
    std::cin.ignore(32000,'\n');
    continue;
}
    break;
}
 int *arr = new int [N];
std::cout << "Enter terms of massive: " << std::endl;
    for(int i = 0; i < N ; i++)
    {
            arr[i] = -1000 + rand() % 5000;
    }
    std::cout << "Your first array: " << std::endl;
    for(int i = 0; i < N ; i++)
    {
        std::cout << std::setw(3) << arr[i] << " ";
    }
    int min_num = arr[0];
    int max_num = arr[0];
    int iMax = 0;
    int iMin = 0;
    for (int i = 0; i < N;i++)
    {
        if (min_num > arr[i])
        {
            min_num = arr[i];
            iMin  = i;
        }
            if (max_num < arr[i]){
                max_num = arr[i];
                iMax = i;
        }
    }
    //


    for(int i = iMin > iMax ? iMax+1 : iMin+1; i < (iMin < iMax ? iMax : iMin);i++)
    {
                arr[i] = 0;
    }
    int null_sum = 0;
    int an_sum = 0;
    for (int i = 0;i < N;i++)
    {
        if(arr[i] == 0)
            null_sum += 1;
        else
            an_sum += 1;
    }
    std::cout << std::endl << "Your new array: " << std::endl;
    if (null_sum > an_sum)
    {
        for(int i=0; i< N; i++)
        {
           if(arr[i]!=0)
               std::cout << std::setw(3) << arr[i] << "  ";
        }
    }
    else
    {
        for(int i=0;i< N; i++)
        {
                std::cout << std::setw(3) << arr[i] << "  ";
        }
    }
    return 0;
}