#include "gtest/gtest.h"
#include <iostream>

int F(int n)
{
    if(!n)
        return  0;
    if(n % 10 > 0)
        return (n % 10);
    else
        return F(n/10);
}

int S(int p,int q)
{
    int res = 0;
    for(int i = p; i <= q;i++)
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