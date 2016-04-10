//  112. Path Sum
//  
//  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
//  For example:
//  Given the below binary tree and sum = 22,
//        5
//       / \
//      4   8
//     /   / \
//    11  13  4
//   /  \      \
//  7    2      1
//
//  return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
//
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/path-sum/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;

        if(root->left == NULL && root->right == NULL) return root->val == sum;

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

TEST(leetcode_112_path_sum, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->hasPathSum(tree_init({"5", "4", "8", "11", "#", "13", "4", "7", "2", "#", "#", "#", "1"}), 22));
    EXPECT_TRUE(solution->hasPathSum(tree_init({"5", "4", "8", "11", "#", "13", "4", "7", "2", "#", "#", "#", "1"}), 18));
    EXPECT_TRUE(solution->hasPathSum(tree_init({"5", "4", "8", "11", "#", "13", "4", "7", "2", "#", "#", "#", "1"}), 26));
    EXPECT_TRUE(solution->hasPathSum(tree_init({"1"}), 1));
    EXPECT_FALSE(solution->hasPathSum(tree_init({"5", "4", "8", "11", "#", "13", "4", "7", "2", "#", "#", "#", "1"}), 25));
    EXPECT_FALSE(solution->hasPathSum(NULL,  0));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
