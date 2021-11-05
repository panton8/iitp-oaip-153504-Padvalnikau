//Лабораторная 4, задача 4. Выполнена: Подвальников А.С.
/*Элемент матрицы называется локальным минимумом,если он строго
меньше всех имеющихся у него соседей.Соседями элемента Akg,где
 i-1< k <i+1 , j-1< g <j+1 ,(k,g) != (i,j).Подсчиать количество
 локальных минимумов заданной матрицы.*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int loc_Min =0,N = 0,M = 0;
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
    int **arr = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int [M];
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
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i =0; i<N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0 && arr[i - 1][j] <= arr[i][j]) {
                loc_Min += 0;
            }
            else if (j > 0 && arr[i][j - 1] <= arr[i][j]) {
                loc_Min += 0;
            } else if (i < N - 1 && arr[i + 1][j] <= arr[i][j]) {
                loc_Min += 0;
            } else if (j < M - 1 && arr[i][j + 1] <= arr[i][j]) {
                loc_Min += 0;
            } else {
                std::cout << "Minimum was found in: " << "Row(" << i + 1 << ") column(" << j + 1 << ") , locMin = " << arr[i][j] << std::endl;
                loc_Min++;
            }
        }
    }
    std::cout << "Found " << loc_Min << " local minimums";
    for(int i = 0; i < M; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}