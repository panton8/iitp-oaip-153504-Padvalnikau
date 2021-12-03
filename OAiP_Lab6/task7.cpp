#include <iostream>
#include <cstring>

char* substr(std::string str, int from, int size){    // Return substring
    char * temp_str = new char[size + 1];
    int j = 0;
    for (int i = from; i < from + size; i++)
        temp_str[j++] = str[i];
    temp_str[size] = 0;
    return temp_str;
}

bool equalChar(std::string str) {     // Checking if a string is a set of identical characters
    for (int i = 0; i < size(str); i++) {
        if (str[i] != str[0])
            return false;
    }
    return true;
}

bool palindrome(std::string str) {      // Checking if a string is a palindrome
    for (int i = 0; i < size(str)/2; i++) {
        if (str[i] != str[size(str) - i - 1])
            return false;
    }
    return true;
}

int main() {
    std::string str;
    std::cout << "Enter the word: " << std::endl;
    getline(std::cin,str);
    if (equalChar(str))
        return -1;
    else {
        if (!palindrome(str))
            std::cout << str.length();
        else {
            if (str[0] < str[1])
                std::cout << strlen(substr(str,0,(str.length()) - 1));
            else
                std::cout << strlen(substr(str,1, (str.length())));
        }
    }
    return 0;
}