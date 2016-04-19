//  342. Power of Four
//  
//  Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//  Example:
//  Given num = 16, return true.
//  Given num = 5, return false.
//  Follow up: Could you solve it without loops/recursion?
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/power-of-four/    

#include <iostream>
#include <gtest/gtest.h>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log10(num) / log10(4), 1) == 0;
    }
};

TEST(leetcode_342_power_of_four, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isPowerOfFour(4));
    EXPECT_TRUE(solution->isPowerOfFour(16));
    EXPECT_TRUE(solution->isPowerOfFour(64));
    EXPECT_TRUE(solution->isPowerOfFour(256));

    EXPECT_FALSE(solution->isPowerOfFour(0));
    EXPECT_FALSE(solution->isPowerOfFour(3));
    EXPECT_FALSE(solution->isPowerOfFour(5));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
