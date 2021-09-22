//Лабораторная 1, задача 4. Выполнена:  Подвальников А. С.
/* Определить время падения камня на поверхность земли с высоты h.*/
#include <iostream>
#include <cmath>
#define g 9.8

using namespace std;

int main()
{
    float h;
    cin >> h;
    double t = sqrt(2*h/g);
    cout << t ;
    return 0;
}
