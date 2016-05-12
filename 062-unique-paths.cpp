//  62. Unique Paths
//  
//  A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//  How many possible unique paths are there?
//
//  ![Image](http://leetcode.com/wp-content/uploads/2014/12/robot_maze.png)
//
//  Above is a 3 x 7 grid. How many possible unique paths are there?
//  Note: m and n will be at most 100.
//
//  Tags: Array, Dynamic Programming
//  
//  https://leetcode.com/problems/unique-paths/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; i ++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if(i == 1 && j == 1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

TEST(leetcode_062_unique_paths, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(0,     solution->uniquePaths(0, 0));
    EXPECT_EQ(0,     solution->uniquePaths(10, 0));
    EXPECT_EQ(0,     solution->uniquePaths(0, 10));
    EXPECT_EQ(28,    solution->uniquePaths(3, 7));
    EXPECT_EQ(48620, solution->uniquePaths(10, 10));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
