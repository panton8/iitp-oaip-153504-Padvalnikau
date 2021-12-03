//Лабораторная 6, задача 5. Выполнена: Подвальников А.С.
/*Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m. */

#include <iostream>
#include <cmath>

int resFunc(int m,int len,int prefSize,int sufSize,int special_count){
    int free_space = len - (prefSize + sufSize - special_count);
    if (free_space < 0) {
        return 0;
    }
    if (free_space == 0) {
      return 1;
    }
    long long res = pow(26, free_space) * 2;
    return res % m;
}


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

int main(){
    const int size = 15;
    int rep;
    std::cout << "Enter num of input data: " << std::endl;
    rep = inputCheck();
    while (rep) {
        int i = 0, len, prefSize = 0, sufSize = 0, m;
        std::cout << "Enter length of word: " << std::endl;
        len = inputCheck();
        std::cout << "Enter module m: " << std::endl;
        m = inputCheck();
        char pref[size], suf[size];
        std::cout << "Enter prefix: " << std::endl;
        std::cin >> pref;
        std::cout << "Enter suffix: " << std::endl;
        std::cin >> suf;

        for (i = 0; pref[i] != '\0'; i++)
            prefSize++;

        for (i = 0; suf[i] != '\0'; i++)
            sufSize++;

        int start_place = prefSize;

        for (int j = prefSize - 1; j >= 0; j--) {
            start_place--;
            if (pref[j] == suf[0])
                break;
        }
        int special_count = 0;
        i = 0;
        start_place = prefSize - start_place;

        for (int j = start_place - 1; j < prefSize; j++) {
            if (pref[j] != suf[i]) {
                special_count = 0;
                break; }
            special_count++;
            i++;
        }
        std::cout << " Result of operation: " << resFunc(m,len,prefSize,sufSize,special_count) << std::endl;
        rep--;
    }
    return 0;
}