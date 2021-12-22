//Лабораторная 7, задача 3. Выполнена: Подвальников А.С.
/*Найдите сумму двоичных чисел, заданных в естественной
форме. Сложение выполните в дополнительном коде. Ответ
выразите в прямом коде.Разработать функции для выполнения
операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.*/
#include <iostream>

void dop(long long num1, long long num2) {
    std::string str1,str2;
    if (num1 > 0)
        str1 = "00000000000000000000000000000000";
    else if(num1 <= 0)
        str1 = "10000000000000000000000000000000";
    int k = abs(num1);
    for (int i = 31; i > 0; i--) {
        str1[i] = k % 2 + '0';
        k /= 2;
    }
    if (num2 > 0)
        str2 = "00000000000000000000000000000000";
    else if (num2 <= 0)
        str2 = "10000000000000000000000000000000";
    k = abs(num2);
    for (int i = 31; i > 0; i--) {
        str2[i] = k % 2 + '0';
        k /= 2;
    }
    if (num1 < 0) {
        for (int i = 1; i < 32; i++) {
            if (str1[i] == '1')
                str1[i] = '0';
            else
                str1[i] = '1';
        }
        int cu = 1, temp;
        for (int i = 31; i >= 0; i--) {
            temp = str1[i] ^ cu;
            cu = str1[i] & cu;
            str1[i] = temp;
        }
    }
    if (num2 < 0) {
        for (int i = 1; i < 32; i++) {
            if (str2[i] == '1')
                str2[i] = '0';
            else
                str2[i] = '1';
        }
        int cu = 1,temp;
        for (int i = 31; i >= 0; i--) {
            temp = str2[i] ^ cu;
            cu = str2[i] & cu;
            str2[i] = temp;
        }

    }
    int* Ai = new int[32];
    int* Bi = new int[32];
    for (int i = 0; i < 32; i++) {
        Ai[i] = str1[i] - '0';
        Bi[i] = str2[i] - '0';
    }
    if(num1 < 0 && num2 < 0){
        int cu = 0;
        for (int i = 31; i >= 0; i--) {
            Ai[i] += cu;
            if (Ai[i] == 2) {
                Ai[i] = 0;
                cu = 1;
            }
            else
                cu = 0;
            Ai[i] += Bi[i];
            if (Ai[i] == 2) {
                Ai[i] = 0;
                cu = 1;
            }
        }
        for (int i = 1; i < 32; i++) {
            if (Ai[i] == 1)
                Ai[i] = 0;
            else
                Ai[i] = 1;
        }
        if (cu == 1) {
            for (int i = 31; i >= 0; i--) {
                Ai[i] += cu;
                if (Ai[i] > 1) {
                    Ai[i] = 0;
                    cu = 1;
                }
                else
                    cu = 0;
            }
        }
    }
    else {
        int cu = 0;
        for (int i = 31; i >= 0; i--) {
            Ai[i] += cu;
            if (Ai[i] == 2) {
                Ai[i] = 0;
                cu = 1;
            }
            else
                cu = 0;
            Ai[i] += Bi[i];
            if (Ai[i] == 2) {
                Ai[i] = 0;
                cu = 1;
            }
        }
    }
    for (int i = 0; i < 32; i++)
        std::cout << Ai[i];
}

int main() {

    long long num1, num2;
    std::cout << "Enter the num1 in binary notation: " << std::endl;
    while (!(std::cin >> num1)) {
        std::cout << "Incorrect value!Repeat again:";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "Enter num2 in binary notation" << std::endl;
    while (!(std::cin >> num2)) {
        std::cout << "Incorrect value!Repeat again:";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    dop(num1,num2);
    return 0;
}