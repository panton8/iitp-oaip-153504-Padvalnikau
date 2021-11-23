//Лабораторная 5, задача 3(3). Выполнена: Подвальников А.С.
/*Дан двумерный динамический массив целых чисел. Значения элементов данного
массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных в четных столбцах данного массива и имеющих нечетное значение.
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции.*/

#include <iostream>
#include <iomanip>

int inputCheck(){
    int x;
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

void createNewArr(int **A,int N,int M) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((j) && (j % 2 == 0) && (A[i][j] % 2 != 0))
                count++;
        }
    }
    int *B = new int[count];
    int m = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((j) && (j % 2 == 0) && (A[i][j] % 2 != 0)) {
                B[m++] = A[i][j];
            }
        }
    }
    for (int i = 0; i < count; i++)
        std::cout << std::setw(2) << B[i] << " ";
}

double midSum(int **A,int N,int M){
    int sum = 0;
    int elements = 0;
    double midsum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if((j)&& (j % 2 == 0 )&& (A[i][j] % 2 != 0)) {
                sum += A[i][j];
                elements++;
            }
        }
    }
    if(elements)
        midsum = double(sum) / elements;
    else
        midsum = 0;
    return  midsum;
}

int main()
{
    int N = 0, M = 0;
    std::cout << "Enter size of array: " << std::endl;
    N = inputCheck();
    M = inputCheck();
    int **A = new int*[N];
    for (int i = 0; i < N; i++)
        A[i] = new int [M];
    std::cout << "Full array: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            A[i][j] = inputCheck();
        }
    }
    std::cout << "First array: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "New array: " << std::endl;
    createNewArr(A,N,M);
    std::cout << std::endl << "The middle sum of new array: " << midSum(A,N,M) << std::endl;
    for(int i = 0; i < N; i++)
        delete[]A[i];
    delete[]A;
    return 0;
}