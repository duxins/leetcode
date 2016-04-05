//  226. Invert Binary Tree
//  
//  Invert a binary tree.
//       4
//     /   \
//    2     7
//   / \   / \
//  1   3 6   9
//
//  to
//       4
//     /   \
//    7     2
//   / \   / \
//  9   6 3   1
//
//  Trivia:
//
//  This problem was inspired by this original tweet by Max Howell:
//  Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
//  Subscribe to see which companies asked this question
//  
//  Tags: Tree
//  
//  https://leetcode.com/problems/invert-binary-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include "tree/tree.h"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};

TEST(leetcode_226_invert_binary_tree, Basic)
{
    Solution *solution = new Solution();
    TreeNode *t1 = tree_init({"4", "2", "7", "1", "3", "6", "9"});
    TreeNode *expected = tree_init({"4", "7", "2", "9", "6", "3", "1"});
    TreeNode *result = solution->invertTree(t1);
    EXPECT_TRUE(tree_equal(expected, result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
