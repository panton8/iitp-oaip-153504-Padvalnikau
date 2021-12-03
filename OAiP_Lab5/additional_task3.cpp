//Лабораторная 5, задача 6. Выполнена: Подвальников А.С.
/*Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).*/

#include <iostream>
#include <cmath>

long long inputCheck(){
    long long x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != int(x) || x != round(x))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    return  x;
}

long long  f(long long n){
    long long k = (n+1)/2;
    if(!n)
        return 0;
    return  k * k + f(n / 2);
}

int main(){
    std::cout << "Enter the parameter: " << std::endl;
    long long n = inputCheck();
    std::cout << f(n);
    return 0;
}