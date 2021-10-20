//Лабораторная 3, задача 2. Выполнена: Подвальников А.С.
/*(использовать do while) Найти сумму ряда с точностью E = 0.001,
общий член которого Dn = 1/2^n + 1/3^n.При составлении программы
считать,что точность достигнута,если Dn < E.*/

#include <iostream>
#include <cmath>
#include <iomanip>

#define E 0.0000001

int main() {
    double sum = 0;
    double Dn;
    int i = 1;
    do {
        Dn = pow(1.0 / 2, i) + pow(1.0 / 3, i);
        sum += Dn;
        i++;
    } while (Dn > E);
    std::cout << std::fixed << std::setprecision(3) << "Sum of your series is " << sum << std::endl;
    return 0;
}