//Лабораторная 4, задача 9. Выполнена: Подвальников А.С.
/*В качестве входных данных поступают две целочисленные
матрицы A и B, которые имеют размер N и соответственно. Требуется найти
произведение матриц A*B. Выделение памяти через функции языка С.*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

int main()
{
    //Enter parameters for A
    int N1 = 0, N2 = 0, M1 = 0, M2 = 0;
    srand(time(nullptr));
    std::cout << "Enter size of array A: " << std::endl;
    while(true)
    {
        std::cin >> N1 >> M1;
        if(std::cin.fail() || (N1 || M1) < 1 ||  (N1 || M1) != (int)(N1 || M1) || (N1 || M1) != round((N1 || M1)))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    //Create array A
    int **A ;
    A = (int **) malloc(N1 * sizeof(int *));
    for (int i = 0; i < N1; i++) {
        A[i] = (int *) malloc(M1 * sizeof(int));
    }
    // Input elements (A)
    for (int i=0; i<N1; i++)
    {
        for (int j=0; j<M1; j++)
        {
            A[i][j]= -10 + rand() % 25;
        }
    }
    std::cout << "Array A: " << std::endl;
    for (int i=0; i<N1; i++)
    {
        for (int j=0; j< M1; j++)
        {
            std::cout << std::setw(3) << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // Enter parameters for B
    std::cout << "Enter size of array B: " << std::endl;
    while(true)
    {
        std::cin >> N2 >> M2;
        if(std::cin.fail() || (N2 || M2) < 1 ||  (N2 || M2) != (int)(N2 || M2) || (N2 || M2) != round((N2 || M2)))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        if(M1 != N2)
        {
            std::cout <<"Multiplication impossible! Try again : " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    // Create array B
    int **B ;
    B = (int **) malloc(N2 * sizeof(int *));
    for (int i = 0; i < N2; i++) {
        B[i] = (int *) malloc(M2 * sizeof(int));
    }
    // Input elements(B)
    std::cout << "Enter terms of massive(B): " << std::endl;
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < M2; j++) {
            B[i][j]= -10 + rand() % 30;
        }
    }
    std::cout << "Array B: " << std::endl;
    for (int i=0; i<N2; i++)
    {
        for (int j=0; j< M2; j++)
        {
            std::cout << std::setw(3) << B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // Create array C
    int** C = (int**)calloc(N1, sizeof(int*));
    for (int i = 0; i < N1; i++)
    {
        C[i] = (int*)calloc(M2, sizeof(int));
    }
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // Output array C
    std::cout << "ARRAY C:" << std::endl;
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < M2; j++)
            std::cout << std::setw(4) << C[i][j] << " ";
        std::cout << std::endl;
    }
    free(A);
    free(B);
    free(C);
    return 0;
}