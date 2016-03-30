//  263. Ugly Number
//  
//  Write a program to check whether a given number is an ugly number.
//  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//  Note that 1 is typically treated as an ugly number.
//
//  Tags: Math
//  
//  https://leetcode.com/problems/ugly-number/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        if(num % 2 == 0) return isUgly(num/2);
        if(num % 3 == 0) return isUgly(num/3);
        if(num % 5 == 0) return isUgly(num/5);
        return (num == 1);
    }
};

TEST(leetcode_263_ugly_number, Basic)
{
    Solution *solution = new Solution();
    EXPECT_FALSE(solution->isUgly(0));
    EXPECT_FALSE(solution->isUgly(14));
    EXPECT_FALSE(solution->isUgly(21));

    EXPECT_TRUE(solution->isUgly(1));
    EXPECT_TRUE(solution->isUgly(2));
    EXPECT_TRUE(solution->isUgly(10));
    EXPECT_TRUE(solution->isUgly(30));
    EXPECT_TRUE(solution->isUgly(15));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
