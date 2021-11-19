//Лабораторная 5, задача 2(1). Выполнена: Подвальников А.С.
/*Для заданного одномерного массива А из N элэментов проверить,что
существует,по крайней мере,один элемент Аi,для которого выполняется
условие sin Ai > 0.Рекурсивную функцию применять отдельно для каждой
из половин массива.Рекурсивные вызовы заканчивать,когда останется
только один элемент.*/

#include <iostream>
#include <cmath>
#include "library.h"

int inputCheck(){
    int x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != (int)x || x != round(x))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    return  x;
}

bool check(int *A, int N)
{
   if (N == 1)
       return sin(A[0]) > 0;
   int middle = N/2;
   int *left  = new int [middle];
   left = copy::copy_arr(A,0, middle);
   int *right = new int[N - middle];
   right = copy::copy_arr(A, middle, N);
   return check(left, middle) || check(right, middle);
}

int main()
{
    std::cout << "Enter size of array: " << std::endl;
    int N = inputCheck();
    int *A = new int[N];
    std::cout << "Enter elements of array: " << std::endl;
    for(int i = 0; i < N; i++)
    {
      A[i] = inputCheck();
    }
    for(int i = 0;i < N;i++)
    {
        std::cout << "sin(A[i]) = " << sin(A[i]) << std::endl;
    }
    std::cout << std::endl << "Result of checking: " << check(A,N) << std::endl;
    delete []A;
    return 0;
}