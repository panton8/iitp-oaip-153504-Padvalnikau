//Лабораторная 2, задача 9. Выполнена: Подвальников А.С.
/*Даны действительные положительные числа x, y, z. Выяснить,
существует ли треугольник с длинами сторон x, y, z.*/
#include <iostream>

using namespace std;

int main()
{
    float x,y,z;
    cin >> x >> y >> z;
    if (x < y+z && y < x+z && z < x+y)
    {
        cout << "Exists";
    }
    else
    {
        cout << "Doesn't exist";
    }
    return 0;
}

