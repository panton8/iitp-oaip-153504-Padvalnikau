#include "gtest/gtest.h"
#include <iostream>
#include <cmath>

unsigned long long f(unsigned long long n,unsigned long long r, unsigned long long i){
    if (!r) return 1 % i;

    if (r % 2 ) return (n * f(n,r-1,i)) % i;

    return f((n * n) % i, r / 2, i);
}

TEST(func2_test,test1){
    EXPECT_EQ(736, f(1234,1234,pow(10,4)));
    EXPECT_TRUE(true);
}

TEST(func2_test,test2){
    EXPECT_EQ(39087387, f(2323,99999999999,pow(10,8)));
    EXPECT_TRUE(true);
}

TEST(func2_test,test3){
    EXPECT_EQ(494777344,f(4,99999,pow(10,9)));
    EXPECT_TRUE(true);
}

TEST(func2_test,test4) {
    EXPECT_EQ(91255296, f(888,888,pow(10,8)));
    EXPECT_TRUE(true);
}

TEST(func2_test,test5) {
    EXPECT_EQ(NULL, f(0,0,pow(10,0)));
    EXPECT_TRUE(true);
}