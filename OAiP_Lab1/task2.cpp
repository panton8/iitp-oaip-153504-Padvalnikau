//Лабораторная 1, задача 2. Выполнена:  Подвальников А. С.
/* Составить программу на языке С++ для расчета соотношения. Исходные
данные ввести с клавиатуры .*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float n,m,x,K;
    cin >> n >> m >> x >> K;
    float D = tan(x);
    float A = fabs (n+m);
    double y = 1.29 + K/A + pow(D,2);
    cout << y;
    return 0;

}