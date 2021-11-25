//Лабораторная 5, задача 3(2). Выполнена: Подвальников А.С.
/*Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.*/

#include <iostream>
#include <iomanip>

double inputCheck(){
    double x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != (int)x )
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

void workWithArray(double **A,int N,int M)
{
    int count = 0;
    std::cout << std::endl << "Element of array with value 0 has indices: " << std::endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(A[i][j] == 0){
                std::cout << "[i] = " << i << " [j] = " << j << std::endl;
                count++;
            }
        }
    }
    if(!count)
    {
        std::cout << "No indices,because array haven't got elements with value 0" << std::endl;
        std::cout << std::endl << "Num of element with value 0: " << 0 << std::endl;
    }
    else
        std::cout << "Num of element with value 0: " << count << std::endl;
    for(int i = 0; i <N; i++)
        delete[]A[i];
    delete[]A;
}

void reverseA(double **A,int  N,int M)
{
    double  **B = new double*[N];
    for(int i = 0; i < N; i++)
        B[i] = new double[M];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            B[i][j] = A[i][j];

        }
    }
    int m = M - 1;
    int k = M - 1;
    int p = N - 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            A[i][j] = B[k][p];
            p--;
            if(j == m)
            {
                k--;
                p = m;
            }
        }
    }
    std::cout << std::endl << "Reverse array: " << std::endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cout << std::setw(2) << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < N; i++)
        delete[]B[i];
    delete[]B;
}

int main()
{
    int N = 0,M = 0;
    std::cout << "Enter size of array: " << std::endl;
    std::cin >> N >> M;
    double **A = new double*[N];
    for(int i = 0; i < N; i++)
        A[i] = new double[M];
    std::cout << "Full array: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++){
            A[i][j] = inputCheck();
        }
    }
    std::cout << "Array: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++){
            std::cout << std::setw(2)<< A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    workWithArray(A,N,M);
    reverseA(A,N,M);
    for(int i = 0; i < N; i++)
        delete[]A[i];
    delete[] A;
    return 0;
}