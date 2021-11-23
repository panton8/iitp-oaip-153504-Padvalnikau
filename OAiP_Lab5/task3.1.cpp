//Лабораторная 5, задача 3. Выполнена: Подвальников А.С.
/*Дан двумерный динамический массив целых чисел А размерностью n * k .
Размерность массива (n = 5, k = 6) ввести с клавиатуры. Значения элементов массива
ввести с клавиатуры. Создать динамический массив из элементов, расположенных на
главной диагонали матрицы и имеющих четное значение. Вычислить произведение элементов
динамического массива.Созданный массив и результат произведения вывести на экран.
Использовать функции.*/

#include <iostream>
#include <iomanip>
#include <cmath>

int size;

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

void ResSpecificArr(int **A,int n,int k)
{
    int *B = new int[size];
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(i == j && A[i][j] % 2 == 0)
            {
                B[m++] = A[i][j];
            }
        }
    }
    int mplp = 1;
    for(int i = 0; i < size; i++)
    {
        mplp *= B[i];
        if (size == 1 || size == 0)
            mplp = 0;
        std::cout << std::setw(3) << B[i] << " ";
    }
        std::cout << std::endl << "The result of multiplying the elements of the array: " << mplp << std::endl;
    delete[]B;
}

int main()
{
    std::cout << "Enter size of array(n*k):" << std::endl;
    int n = inputCheck();
    int k = inputCheck();
    int **A = new int*[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[k];
    }
    std::cout << "Enter elements of array: " << std::endl;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
           A[i][j] = inputCheck();
            if((i == j) && (A[i][j] % 2 == 0))
                size++;
        }
    }
    std::cout << "Your first array: " << std::endl;
    for(int i = 0;i < n;i++)
    {
        for (int j = 0; j < k; j++)
        {
            std::cout << std::setw(3)  << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    if(size) {
        std::cout << std::endl << "Your new array: " << std::endl;
        ResSpecificArr(A, n, k);
    }
    else {
        std::cout << std::endl << "This array can't be created!" << std::endl;
    }
    for(int i = 0; i < n; i++)
    {
        delete[]A[i];
    }
    delete[]A;
    return 0;
}