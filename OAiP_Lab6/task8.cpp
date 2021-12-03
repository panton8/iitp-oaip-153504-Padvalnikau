//Лабораторная 6, задача 8. Выполнена: Подвальников А.С.
/*У вас есть строка s и фишка, которую вы можете поставить на любой символ
этой строки.
После того, как вы поставите фишку, вы можете подвинуть ее вправо
несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i+1. Конечно же, это действие невозможно, если
фишка находится в последней позиции строки.
После того, как вы закончите двигать фишку вправо, вы можете подвинуть ее
влево несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i−1. Конечно же, это действие невозможно, если
фишка находится в первой позиции строки.
Когда вы ставите фишку или перемещаете ее, вы выписываете символ, на
котором оказалась фишка. Например, если строка s — abcdef, вы ставите
фишку на 3-й символ, двигаете ее вправо 2 раза, а затем двигаете ее влево 3
раза, вы выпишете строку cdedcb.
Вам даны две строки s и t. Ваше задание — определить, можно ли так
выполнить описанные операции со строкой s, что в результате вы выпишете
строку t.*/

#include <iostream>
#include <cstring>

int inputCheck(){
    int x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != (int)x)
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

void possibleOperation(char *str1, char *str2) {
    int count = 0;
    int check1 = 0;
    int check2 = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;

    for(int k = 0; k < len1; k++){
        for(int j = 0; j < len2 ; j++ ){
            if(str2[j] == str1[i])
                check2++;
        }
    }

    for(int j = 0; j < len1; j++) {
        if(str1[j] == str2[i]){
            check1++;
            i++;
        }
        if(check1 == len2 || (check2 == len1*len2) ){
            std::cout << "Yes" << std::endl;
            break;
        }
        if(count == 2*len2 || ((str1[len1-1] == str2[0]) && (len2 != 1) && (str1[len1-1] != str1[0])) || (str1[len1-1] == str2[i] && str1[len1-1] == str2[i+1] && str1[len1-1] != str1[len1 -2])) {
            std::cout << "NO" << std::endl;
            break;
        }
        if (j == len1-1){
            j = 0;
            count++;
            continue;
        }
    }
}
int main(){
    char *str1 = new char [500];
    char *str2 = new char [999];
    int rep = 0;
    std::cout << "Enter num of input data: " << std::endl;
    rep = inputCheck();
    for(int i = 0; i < rep; i++){
        std::cout << "Enter string1: " << std::endl;
        std::cin.ignore();
        std::cin >> str1;
        std::cout << "Enter string2: " << std::endl;
        std::cin.ignore();
        std::cin >> str2;
        possibleOperation(str1,str2);
    }
    return 0;
}