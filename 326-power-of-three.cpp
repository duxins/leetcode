//  326. Power of Three
//  
//  Given an integer, write a function to determine if it is a power of three.
//  Follow up:
//  Could you do it without using any loop / recursion?
//
//  Tags: Math
//  
//  https://leetcode.com/problems/power-of-three/    

#include <iostream>
#include <gtest/gtest.h>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        while((n % 3) == 0){
            n = n / 3;
        }

        return n == 1 ? true :false;
    }

    bool isPowerOfThreeLogarithmically(int n) {
        // log10(n) / log10(3) = log3(n)
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};

TEST(leetcode_326_power_of_three, Basic)
{
    Solution *s = new Solution();
    EXPECT_TRUE(s->isPowerOfThree(9)) << 9;
    EXPECT_TRUE(s->isPowerOfThree(27)) << 27;
    EXPECT_TRUE(s->isPowerOfThree(81)) << 91;
}

TEST(leetcode_326_power_of_three, Logarithmical)
{
    Solution *s = new Solution();
    EXPECT_TRUE(s->isPowerOfThreeLogarithmically(9)) << 9;
    EXPECT_TRUE(s->isPowerOfThreeLogarithmically(27)) << 27;
    EXPECT_TRUE(s->isPowerOfThreeLogarithmically(81)) << 91;
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
