#include "gtest/gtest.h"
#include <iostream>
#include<cmath>

long long f(long long n){
    long long k = (n+1)/2;
    if(!n)
        return 0;
    return  k * k + f(n / 2);
}

TEST(func_test3,test1){
    EXPECT_EQ(21, f(7));
    EXPECT_TRUE(true);
}

TEST(func_test3,test2){
    EXPECT_EQ(1, f(1));
    EXPECT_TRUE(true);
}

TEST(func_test3,test3){
    EXPECT_EQ(201537, f(777));
    EXPECT_TRUE(true);
}
TEST(func_test3,test4){
    EXPECT_EQ(333333333334181226, f(pow(10,9)));
    EXPECT_TRUE(true);
}