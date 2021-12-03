//Лабораторная 5, задача 5. Выполнена: Подвальников А.С.
/*Определим следующую рекурсивную функцию F(n).Вычислить значение x.*/

#include <iostream>
#include <cmath>

unsigned  long long inputCheck(){
    unsigned long long x;
    while(true)
    {
        std::cin >> x;
        if(std::cin.fail() ||  x != (unsigned  long long)x || x == 0)
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

unsigned long long f(unsigned long long n,unsigned long long r, unsigned long long i)

{
    if (!r) return 1 % i;

    if (r % 2 ) return (n * f(n,r-1,i)) % i;

    return f((n * n) % i, r / 2, i);
}

int main() {
    std::cout << "Enter parameters of k,n,t: " << std::endl;
    unsigned long long k = inputCheck();
    unsigned long long n = inputCheck();
    unsigned long long t = inputCheck();
    unsigned long long m = pow(10, t);
    std::cout << "Result of the operation: " << f(k, n, m) << std::endl;
    return 0;
}