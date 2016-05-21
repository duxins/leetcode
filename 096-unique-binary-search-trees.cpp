//  96. Unique Binary Search Trees
//  
//  Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//  For example,
//
//  Given n = 3, there are a total of 5 unique BST's.
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3
//
//  Tags: Tree, Dynamic Programming
//  
//  https://leetcode.com/problems/unique-binary-search-trees/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

TEST(leetcode_096_unique_binary_search_trees, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->numTrees(1));
    EXPECT_EQ(2, solution->numTrees(2));
    EXPECT_EQ(5, solution->numTrees(3));
    EXPECT_EQ(14, solution->numTrees(4));
    EXPECT_EQ(42, solution->numTrees(5));
    EXPECT_EQ(4862, solution->numTrees(9));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
