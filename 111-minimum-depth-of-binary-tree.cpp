//  111. Minimum Depth of Binary Tree
//  
//  Given a binary tree, find its minimum depth.
//  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//  Tags: Tree, Depth-first Search, Breadth-first Search
//  
//  https://leetcode.com/problems/minimum-depth-of-binary-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left == NULL) return minDepth(root->right) + 1;
        if(root->right == NULL) return minDepth(root->left) + 1;
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};


TEST(leetcode_111_minimum_depth_of_binary_tree, Basic)
{
    Solution *solution = new Solution();

//         1
//       /
//      2

    EXPECT_EQ(2, solution->minDepth(tree_init({"1", "2"})));

//         1
//       /   \
//      2     3
//       \   / \
//        4 5   6
//       /
//      7

    EXPECT_EQ(3, solution->minDepth(tree_init({"1", "2", "3", "#", "4", "5", "6", "7"})));
    EXPECT_EQ(3, solution->minDepth(tree_init({"1", "2", "3", "4", "5", "6", "7", "8"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
