//Лабораторная 6, задача 9. Выполнена: Подвальников А.С.
/*Сумма чисел в строке
В заданной строке, состоящей из букв, цифр и прочих символов, найдите
сумму всех чисел.*/

#include <iostream>
#include <string>

long long numFromString(const char *str) {
    int sum = 0, num = 0;
    for (; *str; str++) {
        if (*str >= '0' && *str <= '9')
            num = num * 10 + (*str - '0');
        else if (num) {
            sum += num;
            num = 0;
        }
    }
    return sum + num;
}

int main(){
    const int N = 80;
    char str[N];
    std::cout << "Enter the string: " << std::endl;
    gets(str);
    std::cout << "Sum of numbers in string: " << numFromString(str);
    return 0;
}