//  110. Balanced Binary Tree
//  
//  Given a binary tree, determine if it is height-balanced.
//  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//  Subscribe to see which companies asked this question
//  
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/balanced-binary-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root){
        if(root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};

TEST(leetcode_110_balanced_binary_tree, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isBalanced(tree_init({"1"})));
    EXPECT_TRUE(solution->isBalanced(tree_init({"1", "2", "3"})));

//     1
//    / \
//   2   3
//        \
//         4

    EXPECT_TRUE(solution->isBalanced(tree_init({"1", "2", "3", "#", "#", "#", "4"})));

//     1
//    / \
//   2   3
//      / \
//     4   5
//    /
//   6

    EXPECT_FALSE(solution->isBalanced(tree_init({"1", "2", "3", "#", "#", "4", "5", "6"})));

//     1
//    / \
//   2   3
//        \
//         4
//          \
//           5

    EXPECT_FALSE(solution->isBalanced(tree_init({"1", "2", "3", "#", "#", "#", "4", "#", "5"})));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
