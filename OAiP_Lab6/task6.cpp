//Лабораторная 6, задача 6. Выполнена: Подвальников А.С.
/*Анаграммой слова называется любая перестановка всех букв слова.
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
SOOL.
Напишите программу, которая выводит количество различных
анаграмм, которые могут получиться из этого слова.*/

#include <iostream>
#include <string>

bool isNumber(std::string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
    return true;
}

std::string inputCheck(){
    std::string str;
    while(true){
        getline(std::cin,str);
        if(isNumber(str))
        {
            std::cout <<"Incorrect type of variable! Please,enter your value again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(32000,'\n');
            continue;
        }
        break;
    }
    return str;
}

long long fact(long long n){
    if (n == 1)
        return 1;
    return n * fact(n-1);
}

long  long repetitions(std::string str){
    char sym[100];
    int sum[100];
    for (int i = 0; i < std::size(str); i++)
        sum[i] = 1;
    for (int j = 0; j < std::size(str);j++)
    {
        sym[j] = str[j];
        for (int k = j+1; k < std::size(str); k++)
        {
            if (str[j] == str[k])
            {
                sum[j]++;
                sum[k] = sum[k] - 10;
            }
        }
    }
    long long res = 1;
    for(int i = 0; i < std::size(str); i++){
        if (sum[i] > 0)
            res *= fact(sum[i]);
    }
    return res;
}

int main()
{
    std::cout << "Enter word to find anagrams: " << std::endl;
    std::string str = inputCheck();
    std::cout << "Word: " << str << std::endl;
    long long numerator = fact(std::size(str));
    long long denominator = repetitions(str);
    long long anagrams = numerator / denominator;
    std::cout << "The number of anagrams: " << anagrams;
    return 0;
}