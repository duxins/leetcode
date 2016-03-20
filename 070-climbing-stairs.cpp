//  70. Climbing Stairs
//  
//  You are climbing a stair case. It takes n steps to reach to the top.
//  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//  Subscribe to see which companies asked this question
//  
//  Tags: Dynamic Programming
//  
//  https://leetcode.com/problems/climbing-stairs/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp {0, 1, 2};

        for(int i = 3; i<= n; i++){
            dp.push_back(dp[i-1] + dp[i-2]);
        }

        return dp[n];
    }
};

TEST(leetcode_070_climbing_stairs, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->climbStairs(1));
    EXPECT_EQ(2, solution->climbStairs(2));
    EXPECT_EQ(3, solution->climbStairs(3));
    EXPECT_EQ(89, solution->climbStairs(10));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
