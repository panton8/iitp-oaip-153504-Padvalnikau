//Лабораторная 4, задача 3. Выполнена: Подвальников А.С.
/*В вещесвенной матрице размером NxN найти максимальный и минимальный
элементы.Переставить строки в которых они находятся,если они находятся
в одной строке,выдать об этом сообщение.*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int N = 0;
    std::cout << "Enter size of array(NxN): " << std::endl;
    while(true)
    {
        std::cin >> N;
        if(std::cin.fail() || N < 2 ||  N != (int)N || N!= round(N))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    int **arr = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int [N];
    }
    std::cout << "Enter terms of massive: " <<std::endl;
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
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
    std::cout << "Your first array: " << std::endl;
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int str_min ;
    int str_max ;
    int min = arr[0][0];
    int max = arr[0][0];
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {

           if(arr[i][j] < min) {
               min = arr[i][j];
               str_min = i;
           }
            if(arr[i][j] > max) {
                max = arr[i][j];
                str_max = i;
            }

        }
    }
    if(str_min == str_max)
    {
        std::cout << "Maximum and minimum values are in the same row";
        std::cout << std::endl;
    }
    else
    {
        std::swap (str_max,str_min);
        for (int i = 0; i < N && str_min != str_max; i++)
        {
            int temp;
            temp = arr[str_max][i];
            arr[str_max][i] = arr[str_min][i];
            arr[str_min][i] = temp;
        }
        std::cout << std::endl;
        std::cout << "Your new array: " << std::endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cout << std::setw(3) << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    for(int i = 0;i < N; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
    return 0;
}