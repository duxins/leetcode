//  343. Integer Break
//  
//  Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those
//  integers. Return the maximum product you can get.
//
//  For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//  Note: you may assume that n is not less than 2.
//  There is a simple O(n) solution to this problem.
//  You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
//
//  Tags: Dynamic Programming, Math
//  
//  https://leetcode.com/problems/integer-break/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) {
           return 1;
        }
        vector<int> dp(n+1, 0);

        dp[1] = 0;
        dp[2] = 1;

        for(int i = 3; i<=n; i++){
            for(int j = 1; j <= i/2; j++){
                int k = i - j;
                dp[i] = max(dp[i], max(j * k, j * dp[k]) );
            }
        }

        return dp[n];
    }
};

TEST(leetcode_343_integer_break, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->integerBreak(2));
    EXPECT_EQ(2, solution->integerBreak(3));
    EXPECT_EQ(4, solution->integerBreak(4));
    EXPECT_EQ(6, solution->integerBreak(5));
    EXPECT_EQ(9, solution->integerBreak(6));
    EXPECT_EQ(12, solution->integerBreak(7));
    EXPECT_EQ(18, solution->integerBreak(8));
    EXPECT_EQ(27, solution->integerBreak(9));
    EXPECT_EQ(2187, solution->integerBreak(21));
    EXPECT_EQ(2916, solution->integerBreak(22));
    EXPECT_EQ(4374, solution->integerBreak(23));
    EXPECT_EQ(8748, solution->integerBreak(25));
    EXPECT_EQ(78732, solution->integerBreak(31));
    EXPECT_EQ(118098, solution->integerBreak(32));
    EXPECT_EQ(4782969, solution->integerBreak(42));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
