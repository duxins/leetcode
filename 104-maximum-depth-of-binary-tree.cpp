//  104. Maximum Depth of Binary Tree
//  
//  Given a binary tree, find its maximum depth.
//  The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//  Subscribe to see which companies asked this question
//  
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/maximum-depth-of-binary-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
	    return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

TEST(leetcode_104_maximum_depth_of_binary_tree, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(2, solution->maxDepth(tree_init({"1", "2", "3"})));
    EXPECT_EQ(3, solution->maxDepth(tree_init({"1", "2", "3", "4", "5"})));
    EXPECT_EQ(4, solution->maxDepth(tree_init({"1", "2", "3", "4", "#", "#", "#", "5"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
