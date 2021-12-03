//Лабораторная 5, задача 4. Выполнена: Подвальников А.С.
/*Определим следующую рекурсивную функцию F(n).Определим функцию S (p, q).
По заданным p и q необходимо вычислить S (p, q).*/

#include <iostream>
#include <cmath>

long long inputCheck(){
    long long x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != (int)x || x != round(x) || x < 0)
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


long long F(long long n)
{
    if(!n)
        return  0;
    if(n % 10 > 0)
        return (n % 10);
    else
        return F(n/10);
}

long long S(long long p,long long q)
{
    long long res = 0;
    for(long long i = p; i <= q;i++)
    {
        res += F(i);
    }
    return res;
}

int main()
{
    std::cout << "Enter value of p and q(p <= q) : " << std::endl;
    int p = inputCheck();
    int q = inputCheck();
    std::cout << S(p,q);
    return 0;
}