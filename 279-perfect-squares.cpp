//  279. Perfect Squares
//  
//  Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//  For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//
//  Tags: Dynamic Programming, Breadth-first Search, Math
//  
//  https://leetcode.com/problems/perfect-squares/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);

        for(int i = 0; i <= n; i++){
            dp[i] = i;

            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }

        }

        return dp[n];
    }
};


TEST(leetcode_279_perfect_squares, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->numSquares(1));
    EXPECT_EQ(2, solution->numSquares(8));
    EXPECT_EQ(1, solution->numSquares(9));
    EXPECT_EQ(3, solution->numSquares(12));
    EXPECT_EQ(2, solution->numSquares(13));
    EXPECT_EQ(3, solution->numSquares(14));
    EXPECT_EQ(3, solution->numSquares(99));
    EXPECT_EQ(2, solution->numSquares(101));
    EXPECT_EQ(2, solution->numSquares(1000));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
