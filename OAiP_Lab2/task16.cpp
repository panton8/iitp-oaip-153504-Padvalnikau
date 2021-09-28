//Лабораторная 2, задача 16. Выполнена: Подвальников А.С.
/*Введены два числа. Выведите их НОД и НОК*/
#include <iostream>

using namespace std;

int main()
{
    int num1,num2,a,b,temp,GCD,LCM;
    cin >> num1 >> num2;
    a = num1;
    b = num2;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    GCD = a;
    LCM = (num1 * num2)/ GCD;
    cout << "Greatest Common Factor Of " << num1 << " And " << num2 << ": " << GCD << endl;
    cout << "Least Common Multiple Of " << num1 << " And " << num2 << ": " << LCM << endl;
    return 0;
}