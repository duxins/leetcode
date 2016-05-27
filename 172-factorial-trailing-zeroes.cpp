//  172. Factorial Trailing Zeroes
//  
//  Given an integer n, return the number of trailing zeroes in n!.
//  Note: Your solution should be in logarithmic time complexity.
//
//  Tags: Math
//  
//  https://leetcode.com/problems/factorial-trailing-zeroes/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0){
            n = n / 5;
            count += n;
        }
        return count;
    }
};

TEST(leetcode_172_factorial_trailing_zeroes, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(2, solution->trailingZeroes(10));
    EXPECT_EQ(3, solution->trailingZeroes(18));
    EXPECT_EQ(220, solution->trailingZeroes(888));
    EXPECT_EQ(24999, solution->trailingZeroes(100000));
    EXPECT_EQ(452137076, solution->trailingZeroes(1808548329));
    EXPECT_EQ(536870902, solution->trailingZeroes(INT_MAX));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
