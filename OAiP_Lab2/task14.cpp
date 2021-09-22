//Лабораторная 2, задача 14. Выполнена: Подвальников А.С.
/*Даны действительные числа a, b, c, x, y. Выяснить, пройдёт ли
кирпич с ребрами a, b, c в прямоугольное отверстие со стороны x и y.
просовывать кирпич в отверстие разрешается только так, чтобы каждое из его
было параллельно или перпендикулярно каждый из сторон отверстия.*/
#include <iostream>

using namespace std;

int main()
{
    double a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if (c <= y && b <= x)
    {
        cout << "Brick passes";
    }
    else if (c <= y && a<= x)
    {
        cout << "Brick passes";
    }
    else if (a <= x && b<=y)
    {
        cout << "Brick passes";
    }
    else if (a <= y && b <= x)
    {
        cout << "Brick passes";
    }
    else if (c <= x && a <= y)
    {
        cout << "Brick passes";
    }
    else if (c <= x && b <= y)
    {
        cout << "Brick passes";
    }
    else
    {
        cout << "Brick doesn't passes";
    }
    return 0;
}
