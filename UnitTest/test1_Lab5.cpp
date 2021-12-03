#include "gtest/gtest.h"
#include <iostream>

long long F(long long n)
{
    if(!n)
        return  0;
    if(n % 10 > 0)
        return (n % 10);
    else
        return F(n/10);
}

long long S(long long p,long long q)
{
    int res = 0;
    for(long long i = p; i <= q;i++)
    {
        res += F(i);
    }
    return res;
}

TEST(func_test1,test1){
EXPECT_EQ(46, S(1,10));
EXPECT_TRUE(true);
}

TEST(func_test1,test2){
    EXPECT_EQ(48, S(10,20));
    EXPECT_TRUE(true);
}

TEST(func_test1,test3){
    EXPECT_EQ(52, S(30,40));
    EXPECT_TRUE(true);
}

TEST(func_test1,test4){
    EXPECT_EQ(NULL, S(-1,-1));
    EXPECT_TRUE(true);
}
TEST(func_test1,test5){
    EXPECT_EQ(7, S(INT32_MAX,INT32_MAX));
    EXPECT_TRUE(true);
}