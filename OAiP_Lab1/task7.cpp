//Лабораторная 1, задача 7. Выполнена: Подвальников А. С.
/*Разработка программы обмена местами двух целочисленных
ячеек памяти без использования дополнительный памяти. Программа
должна запросить у пользователя два целый числа, затем выполнить
реализованный алгоритм по шагам, показывая содержимое ячеек памяти до
первого шага и после каждого шага. Во время выполнения данного алгоритма
могут возникать целочисленные переполнения ячеек; нужно уметь правильно
определить, где и почему они возникли. */
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    a = a^b;
    b = b^a;
    a = a^b;
    cout << a << " " << b;
    return 0;
}
