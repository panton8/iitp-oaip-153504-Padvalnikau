//Лабораторная 1, задача 3. Выполнена:  Подвальников А. С..
/* На вход даны 6 чисел x1, y1; x2, y2; x3, y3 - координаты вершин А, В, С
//соответственно. Необходимо вычислить:
//1) Длину всех сторон треугольника.
//2) Длину всех высот треугольника.
//3) Длину всех медиан треугольника.
//4) Длину всех биссектрис треугольника.
//5) Градусную и радианную меру углов треугольника.
//6) Радиусы вписанной и описанной окружностей треугольника.
//7) Найти площадь и длину этих окружностей.
//8) Площадь и периметр треугольника.*/
#include <iostream>
#include <cmath>
#define PI 3.14159265

using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1;
    while(true)
    {
        printf("kek");
    }
    cin >> x2 >> y2 >> x3 >> y3;
    double AB = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    double AC = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    double BC = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    double p = (AB+AC+BC)/2;
    double H1 = 2*sqrt(p*(p-AB)*(p-BC)*(p-AC))/AB;
    double H2 = 2*sqrt(p*(p-AC)*(p-BC)*(p-AB))/AC ;
    double H3 = 2*sqrt(p*(p-BC)*(p-AB)*(p-AC))/BC;
    double M1 = sqrt(2*pow(AC,2) + pow(BC,2)-pow(AB,2))/2;
    double M2 = sqrt(2*pow(AB,2) + pow(BC,2)-pow(AC,2))/2;
    double M3 = sqrt(2*pow(AB,2) + pow(AC,2)-pow(BC,2))/2;
    double L1 = sqrt(AB*AC*(AB+AC+BC)*(AB+AC-BC))/(AB+AC);
    double L2 = sqrt(AB*BC*(AB+BC+AC)*(AB+BC-AC))/(AB+BC);
    double L3 = sqrt(BC*AC*(BC+AC+AB)*(BC+AC-AB))/(BC+AC);
    double param1 = (pow(BC,2)+pow(AC,2)-pow(AB,2))/(2*BC*AC);
    double param2 = (pow(BC,2)+pow(AB,2)-pow(AC,2))/(2*BC*AB);
    double param3 = (pow(AB,2)+pow(AC,2)-pow(BC,2))/(2*AB*AC);
    double angle1 = acos(param1)*180/ PI;
    double angle2 = acos(param2)*180/ PI ;
    double angle3 = acos(param3)*180/ PI;
    double angleR1 = angle1*PI/180;
    double angelR2 = angle2*PI/180;
    double angelR3 = angle3*PI/180;
    double R = (AB*BC*AC)/(4*sqrt(p*(p-AB)*(p-BC)*(p-AC)));
    double r = sqrt((p-AB)*(p-AC)*(p-BC)/p);
    double LR = 2*PI*R;
    double Lr = 2*PI*r;
    double SR = PI*pow(R,2);
    double Sr = PI*pow(r,2);
    double S1 = sqrt(p*(p-AB)*(p-BC)*(p-AC));
    double S2 = (AB*AC*BC)/(4*R);
    double S3 = r*p;
    double P = AB + AC + BC;
    cout << "Length of AB:" << AB << "  , Length of AC:" << AC << "  , Length of BC:" << BC << endl;
    cout << "Length of Height1:" << H1 << "  , Length of Height2:" << H2 << "  , Length of Height3:" << H3 << endl;
    cout <<"Length of Median1:" << M1 << "   , Length of Median2:" << M2 << "  , Length of Median3:" << M3 << endl;
    cout <<"Length of Bisectrix1:" << L1 << "  , Length of Bisectrix2:" << L2 << "  , Length of Bisectrix3:" << L3 << endl;
    cout <<"Size of angle1:" << angle1 << "  , Size of angle2: " << angle2<< "  , Size of angle3: " << angle3 << "  , Size of angle1(rad):" << angleR1 << "  , Size of angle2(rad):" << angelR2 << "  , Size of angle3(rad):" << angelR3 << endl;
    cout << "Length of radius1:" << R << "  , Length of radius2:" << r << endl ;
    cout << "Size of area1(circle):" << SR << "  , Size of area2(circle):" << Sr << "  , Length of circle1: " << LR << "  , Length of circle2: " << Lr << endl;
    cout << "Size of area(triangle):" << S1 << "  , Size of area(triangle):" << S2 << "  , Size of area(triangle):" << S3 << "  , Size of perimeter:" << P;
    return 0;
}
