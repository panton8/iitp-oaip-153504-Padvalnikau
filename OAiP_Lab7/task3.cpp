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

std::string additionalCode(std::string str){
    std::string additional_code;
    int a = 0;
    for(int i = 0; i < 8; i++) {
        if(str[0] == '-'){
            a = 8;
        }
        if(i == 0 && a == 8)
        {
            additional_code += '1';
        }
        if(a == 8 && i > 0){
            if(str[i] == '1') additional_code += '0';
            if(str[i] == '0') additional_code += '1';
        }
        else if (!a){
            if (str[i] == '0')
                additional_code += '0';
            else if (str[i] == '1')
                additional_code += '1';
        }
    }
    int size = 0;
    for(int i = 0; additional_code[i] != '\0';i++)
        size++;
    additional_code = reverse(additional_code,size);
    for(int i = 0; i < 8; i++){
        if(a == 8 &&  i > size-1 ){
            additional_code += '1';
        }
        if( !a && i > size-1)
            additional_code += '0';
    }
    additional_code = reverse(additional_code,8);
    for(int i = 7; i >= 0; i--){
        if(a == 8){
            if(additional_code[i] == '0') {
                additional_code[i] = '1';
                break;
            }
            if(additional_code[i] == '1')
                additional_code[i] = '0';
        }
    }
    return additional_code;
}

std::string sumInAddCode(std::string str1,std::string str2){
    std::string  add_sum;
    for(int i = 7; i >= 0; i--){
        if (str1[i] != str2[i]){
            add_sum += '1';
        }
        else if(str1[i] == str2[i] == 0) {
            add_sum += '0';
        }
        else if(str1[i] == str2[i] == 1) {
            add_sum += '0';
            if(str1[i-1] != '1') str1[i - 1] = '1';
            else if(str1[i-1] == '1') str2[i-1] = '1';
        }
    }
    add_sum = reverse(add_sum,8);
    return add_sum;
}

int main(){
    std::string str21 , str22;
    std::cout << "Enter the nums in binary: " << std::endl;
    std::cin >> str21 >> str22;
    std::string add_code1 = additionalCode(str21);
    std::string add_code2 = additionalCode(str22);
    std::string add_code_sum = sumInAddCode(add_code1,add_code2);
    std::cout << add_code1 << std::endl;
    std::cout << add_code2 << std::endl;
    std::cout << add_code_sum << std::endl;
    return 0;
}