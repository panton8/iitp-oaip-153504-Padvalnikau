//Лабораторная 4, задача 13. Выполнена: Подвальников А.С.
/*У Миши в общежитии всего лишь 1 розетка. Дабы исправить это
недоразумение, Миша купил N удлинителей таких, что i-й удлинитель имеет
a[i] входов. Вычислите, сколько розеток получится у Миши, если он
оптимально соединит удлинители?.*/

#include <iostream>
#include <cmath>
#include <time.h>

int main()
{
    int  n, sum = 0;
    srand(time(nullptr));
    std::cout << "Num of extension cords: " << std::endl;
        while(true)
        {
            std::cin >> n;
            if(std::cin.fail() ||  n != (int)n || n!= round(n))
            {
                std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
                std::cin.clear();
                std::cin.ignore(32000,'\n');
                continue;
            }
            break;
        }
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 1 + rand() % 10;
    }
    std::cout << "Extension cords have inputs: " << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "; ";
    }
    for (int i = 0; i < n; ++i)
            sum += arr[i] - 1 ;
    std::cout << std::endl <<"Sockets: " << sum + 1;
    delete[] arr;
    return 0;
}