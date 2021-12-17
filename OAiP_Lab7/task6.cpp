//Лабораторная 7, задача 6. Выполнена: Подвальников А.С.
/*Пусть S(x) это сумма цифр числа х,записанного в десятичной системе
счисления.Например,S(5) = 5,S(10) = 1,S(322) = 7. Мы будем называть число
х интересным,если S(x+1) < S(x).В каждом тесте дано число n.Ваша задача
посчитать количество чисел х таких,что 1 <= x <= n и х-интересное.*/

#include<iostream>

long long S(long long n){
    if(n == 0)
        return 0;
    return (n % 10) + S(n/10);
}

long long interesting(long long num){
    return (num+1)/10;
}

int main() {
    short count;
    int n;
    std::cout << "Enter num of repeat: " << std::endl;
    std::cin >> count;
    while(count){
        std::cout << "Enter the num: " << std::endl;
        std::cin >> n;
        std::cout << interesting(n) << std::endl;
        count--;
    }
    return 0;
}