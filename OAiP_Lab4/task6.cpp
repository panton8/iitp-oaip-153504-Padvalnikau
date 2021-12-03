//Лабораторная 4, задача 6. Выполнена: Подвальников А.С.
/*Для заданной матрицы А размером NхM построить матрицу В
такого же размера,элементы которой обладают следующим свойством:
элемент В[i,j] равен максимальному из элементов матрицы А,расположенных
левее и выше позиции (i,j),включая позицию (i,j).При этом считается,что
позиция (1,1) - верхняя левая позиция матрицы.*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

int main() {
    int N = 0,M = 0;
    srand(time(nullptr));
    std::cout << "Enter size of array(NxM): " << std::endl;
    while(true)
    {
        std::cin >> N >> M;
        if(std::cin.fail() || (N || M) < 1 ||  (N || M) != (int)(N || M) || (N || M) != round((N || M)))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    int **A = new int* [N];
    for (int i = 0; i < N ; i++)
    {
        A[i] = new int [M];
    }
    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < M + 0; j++)
        {
            A[i][j]= 1 + rand() % 25;
        }
    }
    std::cout << "Array A: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << std::setw(3) << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int **B = new int* [N];
    for (int i = 0; i < N; i++)
    {
        B[i] = new int [M];
    }
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            B[i][j] = A[i][j];
        }
    }
    int max_num = A[0][0];
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(max_num < A[i][j])
                max_num = A[i][j];
            B[i][j] = max_num;
        }
    }
    std::cout << "Array B: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << std::setw(3) << B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0 ;i < N; i++)
    {
        delete[]A[i];
        delete[]B[i];
    }
    delete[]A;
    delete[]B;
    return 0;
}