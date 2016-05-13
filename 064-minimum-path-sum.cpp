//  64. Minimum Path Sum
//  
//  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
//  sum of all numbers along its path.
//
//  Note: You can only move either down or right at any point in time.
//
//  Tags: Array, Dynamic Programming
//  
//  https://leetcode.com/problems/minimum-path-sum/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(j > 0){
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }else{
                    dp[j] = dp[j] + grid[i][j];
                }
            }
        }

        return dp[n - 1];
    }
};

TEST(leetcode_064_minimum_path_sum, Basic)
{
    Solution *solution = new Solution();
    vector<vector<int>> grid = {{1, 2, 3}};
    EXPECT_EQ(6, solution->minPathSum(grid));

    grid = {{1, 2, 3}, {1, 2, 3}};
    EXPECT_EQ(7, solution->minPathSum(grid));

    grid = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    EXPECT_EQ(8, solution->minPathSum(grid));

    grid = {{1, 2, 3, 4}, {1, 2, 3, 4}};
    EXPECT_EQ(11, solution->minPathSum(grid));

    grid = {{1, 2, 3, -1}, {1, 2, 3, -1}};
    EXPECT_EQ(4, solution->minPathSum(grid));

    grid = {{0}};
    EXPECT_EQ(0, solution->minPathSum(grid));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
