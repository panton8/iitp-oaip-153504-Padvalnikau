//Лабораторная 7, задача 4. Выполнена: Подвальников А.С.
/*Осуществить сложение и вычитание чисел в двенадцатеричной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.*/
#include <iostream>

std::string reverse(std::string str, int size) {
    if (size == -1)
        return "";
    else
    {
        char a;
        a = str[size];
        return a + reverse(str, size - 1);
    }
}

std::string sum(std::string str1, std::string str2,int size) {
    std::string sum;
    int new_digit = 0;
    int temp = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str1[i] == 'a')
            temp += 10;
        else if(str1[i] == 'b')
            temp += 11;
        else
            temp = str1[i] - '0';
        if (str2[i] == 'a')
            temp += 10;
        else if(str2[i] == 'b')
            temp += 11;
        else
            temp += str2[i] - '0';
        temp += new_digit;
        new_digit = 0;
        if (temp - 12 == 10) {
            sum += 'a';
        }
        else if( temp - 12 == 11)
            sum += 'b';
        else if (temp > 10) {
            new_digit += 1;
            sum += (char)temp - 12 + '0';
        }
        else if (temp < 10) {
            sum += (char)temp + '0';
        }
        temp = 0;
    }
    for(int i = 0; i < size; i++){
        if(sum[i] == '/') {
            sum.replace(i,1,"b");
        }
    }
    sum = reverse(sum,size);
    return sum;
}
std::string diff(std::string str1, std::string str2, int size) {
    std::string diff = "";
    int cu = 0;
    int temp = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (str1[i] == 'a')
            temp += 10;
        else if(str1[i] == 'b')
            temp += 11;
        else
            temp = str1[i] - '0';
        if (str2[i] == 'a')
            temp -= 10;
        else if(str2[i] == 'b')
            temp -= 11;
        else
            temp -= str2[i] - '0';
        temp += cu;
        cu = 0;
        if (str1[i] < 0) {
            temp += 12;
            cu -= 1;
        }
        diff += (temp + '0');
        temp = 0;
    }
    for(int i = 0; i < size; i++){
        if(diff[i] == '/') {
            diff.replace(i,1,"bb");
        }
        if(diff[i] == '*' && diff[i+1] == '*')
            diff.replace(i-1,2,"55");
    }
    for(int i = 0; i < size; i++){

        if(diff[i] == '*' )
            diff.replace(i,1,"b");
    }
    diff = reverse(diff,size);
    return diff;
}

int main(){
    std::string str1;
    std::string str2;
    std::cout << "Enter nums in system12: " << std::endl;
    std::cin >> str1 ;
    int size1 = 0, size2 = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        size1++;
        if ((str1[i] > '9' || str1[i] < '0') && (str1[i] != 'a')) {
            std::cout << "Введённого числа не существует в одиннадцатеричной системе счисления\n";
            return 1;
        }
    }
    std::cin >> str2;
    for (int i = 0; str2[i] != '\0'; i++) {
        size2++;
        if ((str2[i] > '9' || str2[i] < '0') && (str2[i] != 'a')) {
            std::cout << "Введённого числа не существует в одиннадцатеричной системе счисления\n";
            return 1;
        }
    }

    if(size1 < size2) {
        for (size1 = size1; size2 - size1 > 0; size1++) {
            str1 = "0" + str1;
        }
    }
    else if(size1 > size2){
        for (size2 = size2 ; size1 - size2 > 0; size2++) {
            str2 = "0" + str2;
        }
    }

    std::cout << "The result of adding two numbers: ";
    std::cout << sum(str1,str2,size1);
    std::cout << std::endl;
    std::cout << "The result of subtracting two numbers: ";
    std::cout << diff(str1,str2,size2);
    return 0;
}
