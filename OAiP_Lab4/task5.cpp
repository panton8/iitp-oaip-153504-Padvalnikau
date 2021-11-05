//Лабораторная 4, задача 5. Выполнена: Подвальников А.С.
/*Соседями элемента aij в матрице назовём элементы akg,где
 i-1<k<i+1,j-1<g<.j+1,(k,g) != (i,j).Операция сглаживания
матрицы даёт новую матрицу того же размера,каждый элемент
которой получается как среднее арифмитическое имеющихся
соседей соответсвующего элемента исходной матрицы.Построить
результат сглаживания заданной вещественной матрицы.*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int N = 0,M = 0;
    std::cout << "Enter size of array (NxM): " << std::endl;
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
    double **arr = new double*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new double [M];
    }
    std::cout << "Enter terms of massive: " << std::endl;
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < M ; j++) {
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
    std::cout << "First matrix: " << std::endl;
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            std::cout << std::setw(2) << std::fixed << std::setprecision(1) << arr[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    // create new smoothed array

    double **smoothed_arr = new double*[N];
    for (int i = 0; i < N; i++)
    {
        smoothed_arr[i] = new double [M];
    }
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            smoothed_arr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < N; ++i){
        int cnt = 0;
        double sum = 0.0;
        for (int j = 0; j < M; ++j){
            if ((i + 1) < N){
                sum += arr[i+1][j];
                cnt++;
            }
            if ((j + 1) < M){
                sum += arr[i][j+1];
                cnt++;
            }
            if ((i - 1) >= 0 ){
                sum += arr[i-1][j];
                cnt++;
            }
            if ((j - 1) >= 0 ){
                sum += arr[i][j-1];
                cnt++;
            }
            smoothed_arr[i][j] = sum / cnt;
            cnt = 0;
            sum = 0;
        }
    }
    std::cout << "Smoothed matrix: " << std::endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout << std::setw(2) << std::fixed << std::setprecision(1) << smoothed_arr[i][j] << "    ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
    for(int i = 0; i < N; i++)
    {
        delete[] smoothed_arr[i];
    }
    delete [] smoothed_arr;
    return 0;
}