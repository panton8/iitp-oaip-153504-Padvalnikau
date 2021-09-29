//Лабораторная 2, задача 17. Выполнена: Подвальников А.С.
/*Есть два стола :D
В прямоугольной комнате W на H стоит прямоугольный стол стороны которого
параллельны сторонам комнаты. Нижний левый угол стола находится в точке
(x1, y1), а верхний правый в точке (x2, y2). Вы хотите поставить в эту комнату
ещё один прямоугольный стол с шириной w и высотой h так, чтобы сторона,
соответствующая ширине стола, была параллельна стороне комнаты,
соответствующей её ширине. (столы могут касаться друг друга, но не могут
иметь общей площади).
На какое минимальное расстояние нужно сдвинуть первый стол так,
чтобы в комнату можно было поставить второй стол? Поворачивать столы
- запрещено. В расчётах используется Декартова (от Рене Декарт) система
координат. */
#include <iostream>
#include <cmath>

using namespace  std;

int main()
{
    double W,H,x1,y1,x2,y2,w,h;
    cout << "Enter W,H" << endl;
    cin >> W >> H;
    cout << "Enter x1,y1,x2,y2" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter w,h" << endl;
    cin >> w >> h;
    double d_H1 = y1;
    double d_H2 = H - y2;
    double d_W1 = x1;
    double d_W2 = W - x2;
    double min = 108;
    if (((w <= d_W1) || (h <= d_H1)) || ((w <= d_W2) || (h <= d_H2)))
    {
        cout << "No need to move the table" << endl;
        cout << "Minimum distance to move the table : 0" << endl;
    }
    else if (((w > d_W1) || (h > d_H1)) || ((w > d_W2) || (h > d_H2)))
    {
        cout << "You need to move the table" << endl;
        if ((((h - d_H1) <= d_H2) || ((w - d_W1) <= d_W2)) || (((h - d_H2) <= d_H1) || ((w - d_W2) <= d_W1)))
        {
            if (((h - d_H2 + y1) >= h) && (H > (y2-y1)))
            {
                double min_temp = h - H + y2;
                min = min_temp < min ? min_temp : min;
            }
            if(((w - d_W2 + x1) >= w) && (W > (x2 - x1)))
            {
                double min_temp = w - W + x2;
                min = min_temp < min ? min_temp : min;
            }
            if((d_W2 <= d_W1) && (d_H1 <= d_H2))
            {
                double min_temp = sqrt(pow(((x1 + d_W2)-x1),2) + pow(((y1 - d_H1) - y1),2));
                min = min_temp < min ? min_temp : min;
            }
            if ((d_W2 <= d_W1) && (d_H1 >= d_H2))
            {
                double min_temp = sqrt(pow(((x1 + d_W2)-x1),2) + pow(((y1 + d_H2) - y1),2));
                min = min_temp < min ? min_temp : min;
            }
            if ((d_W2 >= d_W1) && (d_H1 <= d_H2))
            {
                double min_temp = sqrt(pow(((x1 - d_W1)-x1),2) + pow(((y1 - d_H1) - y1),2));
                min = min_temp < min ? min_temp : min;
            }
            if ((d_W2 >= d_W1) && (d_H1 >= d_H2))
            {
                double min_temp = sqrt(pow(((x1 - d_W1)-x1),2) + pow(((y1 + d_H2) - y1),2));
                min = min_temp < min ? min_temp : min;
            }
            cout << "Minimum distance to move the table :" << min;
        }
        else if (((h - d_H1) > d_H2)  || ((h - d_H2) > d_H1) || ((w - d_W1) > d_W2) || ((w - d_W2) > d_W1))
        {
            cout << "But you don't have enough space to move the table" << endl;
            cout << -1;
        }
    }
    return 0;
}