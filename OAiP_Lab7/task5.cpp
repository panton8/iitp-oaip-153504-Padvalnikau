#include <iostream>

int inputCheck(){
    int x;
    while(true){
        std::cin >> x;
        if(std::cin.fail() ||  x != (int)x || x < 0)
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

std::string arabicToRoman(int n) {

    std::string rom_str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while(n - values[i] >= 0)
        {
            result += rom_str[i];
            n -= values[i];
        }
    }
    return result;
}

int main(){
    int ar_num;
    std::cout << "Enter the num: " << std::endl;
    ar_num = inputCheck();
    std::cout <<arabicToRoman(ar_num);
    return 0;
}