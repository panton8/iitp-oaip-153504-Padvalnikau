//Лабораторная 1, задача 1(1). Выполнена: Подвальников А.С.
/*Ввести одномерный статический массив из k чисел.Преобразовать массив
следующим образом:все отрицательные элементы массива пенести в начало,
 сохранив исходное взаимное расположение,как средиотрицательных,так и
 среди остальных элементов массива.*/

#include <iostream>
#include <cmath>

int main()
{
    const int k = 8;
    int arr[k];
    std::cout << "Enter terms of array: " <<std::endl;
    for(int i = 0; i < k ; i++)
        while(true)
        {
            std::cin >> arr[i];
            if(std::cin.fail() ||  i != (long long)i || i!= round(i))
            {
                std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
                std::cin.clear();
                std::cin.ignore(32000,'\n');
                continue;
            }
            break;
        }
    std::cout << "Your array : ";
    for(int i = 0; i < k ; i++)
        std::cout << arr[i] << " ;";
    for(int i = 0; i < k - 1; i++)
    {
        for (int j=0; j<k-1; j++)
            if (arr[j] >=0 && arr[j+1]<0)
                std::swap(arr[j], arr[j+1]);

    }
    std::cout << std::endl << "New view of array is : ";
    for (int j = 0; j < k ; j++)
        std::cout << arr[j] << " ;";
    return 0;
}