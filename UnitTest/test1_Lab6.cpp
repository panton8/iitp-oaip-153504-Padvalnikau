#include "gtest/gtest.h"
#include <iostream>
#include <string>

std::string reform(std::string str)
{
    for(int i = 0; i < size(str); i++){
        if(str[i] == 'c' && (str[i+1] == 'e' || str[i+1] == 'i' || str[i+1] == 'y'))
            str.replace(i,1,"s");
        if(str[i] == 'C' && ((str[i+1] == 'e' || str[i+1] == 'i' || str[i+1] == 'y') || (str[i+1] == 'E' || str[i+1] == 'I' || str[i+1] == 'Y')))
            str.replace(i,1,"S");
        if(str[i] == 'c' && (str[i+1] != 'e' || str[i+1] != 'i' || str[i+1] != 'y'))
            str.replace(i,1,"k");
        if(str[i] == 'C' && ((str[i+1] != 'e' || str[i+1] != 'i' || str[i+1] != 'y') ||(str[i+1] != 'E' || str[i+1] != 'I' || str[i+1] != 'Y')))
            str.replace(i,1,"K");
        if(str[i] == 'q' && str[i+1] == 'u')
            str.replace(i,2,"kv");
        if(str[i] == 'Q' && ((str[i+1] == 'u') || (str[i+1] == 'U')))
            str.replace(i,2,"Kv");
        if(str[i] == 'q')
            str.replace(i,1,"k");
        if(str[i] == 'Q')
            str.replace(i,1,"K");
        if(str[i] == 'x')
            str.replace(i,1,"ks");
        if(str[i] == 'X')
            str.replace(i,1,"Ks");
        if(str[i] == 'w')
            str.replace(i,1,"v");
        if(str[i] == 'W')
            str.replace(i,1,"V");
        if(str[i] == 'p' && str[i+1] == 'h')
            str.replace(i,2,"f");
        if(str[i] == 'P' && ((str[i+1] == 'h')||(str[i+1] == 'H')))
            str.replace(i,2,"F");
        if(str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u')
            str.replace(i,3,"u");
        if(str[i] == 'Y' && (str[i+1] == 'o' || str[i+1] == 'O') && (str[i+2] == 'u' || str[i+2] == 'U'))
            str.replace(i,3,"U");
        if(str[i] == 'o' && str[i+1] == 'o')
            str.replace(i,2,"u");
        if(str[i] == 'O' && (str[i+1] == 'o' || str[i+1] == 'O' ))
            str.replace(i,2,"U");
        if(str[i] == 'e' && str[i+1] == 'e')
            str.replace(i,2,"i");
        if(str[i] == 'E' && (str[i+1] == 'e' || str[i+1] == 'E'))
            str.replace(i,2,"I");
        if(str[i] == 't' && str[i+1] == 'h')
            str.replace(i,2,"z");
        if(str[i] == 'T' && (str[i+1] == 'h' || str[i+1] == 'H'))
            str.replace(i,2,"Z");
        if(str[i] == str[i+1] ){
            str.replace(i+1,1,"");
        }
    }
    return str;
}

TEST(func1_test, test1){
EXPECT_EQ("Tu svift for Ziks, tu kvik for Galov, tu strong for ung Prinse Josef to folov", reform("Too swift for Theex, too quick for Gallow, too strong for young Prince Joseph to follow"));
EXPECT_TRUE(true);
}

TEST(func1_test, test2){
EXPECT_EQ("aple", reform("apple"));
EXPECT_TRUE(true);
}
