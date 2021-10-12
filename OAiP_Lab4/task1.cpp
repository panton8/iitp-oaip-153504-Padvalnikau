//Лабораторная 1, задача 1(1). Выполнена: Подвальников А.С.
/**/

#include <iostream>
int main()
{
    int k;
    std::cout << "Enter k" << std::endl;
    std::cin >> k;
    double massive [k];
    std::cout << "Enter terms of massive" <<std::endl;
    for(int i = 0; i < k ; i++)
        std::cin >> massive[i];
    std::cout << "Your massive : ";
    for(int i = 0; i < k ; i++)
        std::cout << massive[i] << " ";
    int j = 0 ;
    double temp;
    for(int i = 0; i <= k-1 ; i++)
    {
        if(massive [i] < 0)
        {
            temp = massive[i];
            massive [i] = massive [j];
            massive[j] = temp;
            j++;
        }
    }
    std::cout << std::endl << "New view of massive is : ";
    for (j = 0; j <= k - 1 ; j++)
        std::cout << massive[j] << " ";
    return 0;
}