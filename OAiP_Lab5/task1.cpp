//Лабораторная 5, задача 1. Выполнена: Подвальников А.С.
/*Составить программу для решения у равнения ai*x + bj = 0,где ai и bj-
элементы динамических массивов,i = 0,1,...,7, j = 0,1,...,7.Массивы А = а0,а1,...,a7
и В = b0,b1,...,b7 ввести с клавиатуры.При ai != 0 вывести на экран результат,а при
ai = 0 переменной х присвоить значение 0,которое также вывести на экран.Использовать
функции,размерность массивов ввести с клавиатуры,исходные данные ввести с клавиатуры.*/

#include <iostream>
#include "static_lib.h"
#include <cmath>

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

void arr(int* A, int* B, int count)
{
    for(;count > 0;count--)
    {
        std::cout << " a = " << *A << " b = " << *B << " x = " << solution::equation(*A, *B) << std::endl;
        A++, B++;
    }
}
int main()
{

    std::cout << "Enter size of arrays A and B: " << std::endl;
    int n = inputCheck();
    int *A = new int[n];
    int *B = new int[n];
    std::cout << "Enter elements of array A:" << std::endl;
    for(int i = 0;i < n; i++) {
        A[i] = inputCheck();
    }
    std::cout << "Enter elements of array B:" << std::endl;
    for(int j = 0;j < n; j++) {
        B[j] = inputCheck();
    }
    arr(A, B, n);
    delete[]A;
    delete[]B;
    return 0;
}