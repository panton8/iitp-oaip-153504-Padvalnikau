//Лабораторная 3, задача 2. Выполнена: Подвальников А.С.
/*(использовать do while) Найти сумму ряда с точностью E = 0.001,
общий член которого Dn = 1/2^n + 1/3^n.При составлении программы
считать,что точность достигнута,если Dn < E.*/

#include <iostream>
#include <cmath>
#include <iomanip>
#define E 0.001

int main()
{
    double sum = 0;
    int n;
    std::cout << "Enter n" << std::endl;
    std::cin >> n;
    if (!std::cin)
    {
        std::cout << "Variable input error" << std::endl;
        return -1;
    }
    double Dn;
    int i = 1;
    do
    {
        Dn = pow(1.0/2,i) + pow(1.0/3,i);
        sum += Dn;
        i++;
    }
    while ((i < n+1) && Dn > E);
        std::cout << std::fixed << std::setprecision(3) << "Sum of your series is " << sum << std::endl;
    return 0;
}