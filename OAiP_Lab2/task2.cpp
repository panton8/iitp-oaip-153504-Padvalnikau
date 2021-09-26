//Лабораторная 2, задача 2. Выполнена: Подвальников А.С.
/*Меньшее из двух значений переменных целого типа Х и Y заменить
нулём, а в случае их равенства - заменить нулями оба; наибольшее из трёх
различных значений переменных вещественного типа А, В и С уменьшите на K.
K вводится с клавиатуры.*/

#include <iostream>

using namespace std;

int main() {
    int X, Y;
    double A,B,C,K;
    cin >> X >> Y >> A >> B >> C >> K;
    if (X > Y)
    {
        Y = 0;
        cout << "X = " << X << endl << "Y = " << Y << endl;
    }
    if (X < Y)
    {
        X = 0;
        cout << "X = " << X << endl << "Y = " << Y << endl;
    }
    if (X == Y)
    {
        (X = Y = 0);
        cout << "X = " << X << endl << "Y = " << Y << endl;
    }
    if (A > B && A > C)
    {
        A = A - K;
        cout << "A(The biggest num) - K = "<< A;
    }
    else if  (B > A && B > C)
    {
        B = B - K;
        cout << "B(The biggest num) - K = " << B;
    }
    else if (C > A && C > B)
    {
        C = C - K;
        cout << "C(The biggest num) - K = " << C;
    }
    return 0;
}