//Лабораторная 3, задача 3. Выполнена: Подвальников А.С.
/*(использовать for) Составить программу вычисления функции
y = sin(x) - cos(x) на отрезке [A,B] в точках Xi = A + i*H,
где Н - (В - А)/М,М = 20,А = 0,В = Pi/2.*/

#include <iostream>
#include <cmath>
#define Pi 3.1415

int main()
{
    double  A = 0;
    double B = Pi / 2;
    double common_result,x,H;
    int i = 1;
    int M = 20;
    H = (B - A)/M;
    x = A + i * H;
    int steps = B / x;
    for (; i <= steps; i++ )
    {
        x = A + i * H;
        common_result = sin(x) - cos(x);
        std::cout << "The result of the calculation with x(" << x << ") =" << common_result << std::endl;
    }
    return 0;
}