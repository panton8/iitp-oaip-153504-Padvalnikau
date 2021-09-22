//Лабораторная 1, задача 6. Выполнена: Подвальников А. С.
/*Студент начал решать задачи данного урока программирования,
когда электронные часы показывали h1 часов и min1 минут, а закончил, когда
было h2 часов и min2 минут. Составьте программу, позволяющую определить,
сколько времени студент решал эти задачи. (Будем считать, что задачи
решались не дольше суток). */
#include <iostream>

using namespace std;

int main()
{
    int h1, min1, h2, min2;
    cin >> h1 >> min1 >> h2 >> min2;
    int time1 = 60*h1 + min1;
    int time2 = (60*h2 + min2)+24*60;
    int result_time = abs(time2 - time1)%(24*60);
    int result_h = result_time / 60;
    int result_min = result_time - 60 * result_h;
    cout << result_h << " hours" << " " << result_min << " minutes";
    return 0;
}
