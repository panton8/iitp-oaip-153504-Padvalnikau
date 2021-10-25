//Лабораторная 4, задача 10. Выполнена: Подвальников А.С.
/*Построить магический квадрат любого порядка, используя любой
алгоритм. Выделение памяти через функции языка С.*/

#include <iostream>
#include <cmath>

int main()
{

    int N = 0,i,j;
    std::cout << "Enter size of your magic square: " << std::endl;
    while(true)
    {
        std::cin >> N;
        if(std::cin.fail() ||  N != (long long)N || N < 0 || N!= round(N))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    int arr [N][N];
    std::cout << "Enter terms of massive" <<std::endl;
    for(i = 0; i < N ; i++)
    {
        for(j = 0; j < N ; j++) {
            while(true)
            {
                std::cin >> arr[i][j];
                if(std::cin.fail() ||  i != (long long)i || i!= round(i) || j != (long long)j || j!= round(j))
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
    for(i = 0; i < N ; i++)
    {
        for(j = 0; j < N ; j++)
        {
            std::cout << arr[i][j] << " ";
            if (j == N - 1)
                std::cout << std::endl;
        }
    }
    while(true)
    {
        bool check = true;
        int column = 0, line = 0;
        for(int i = 0; i < N; i++)
        {
            column += arr[i][0];
        }

        for(int j = 0; j < N; j++)
        {
            line += arr[0][j];
        }

        if(column != line)
        {
            std::cout << "\nIt's not a magic square\n";
            check = false;
        }
        if(check == false)
            break;
        line = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                line += arr[i][j];
            }
            if(column != line)
            {
                std::cout << "\nIt's not a magic square\n";
                check = false;
                break;
            }
            line = 0;
        }
        if(check == false)
            break;
        line = column;
        column = 0;
        for(int j = 0; j < N; j++)
        {
            for(int i = 0; i < N; i++)
            {
                column += arr[i][j];
            }
            if(column != line)
            {
                std::cout << "\nIt's not a magic square\n";
                check = false;
                break;
            }
            column = 0;
        }
        if(check == false)
            break;
        std::cout << "\nIt's a magic square\n";
        break;
    }
    return 0;
}