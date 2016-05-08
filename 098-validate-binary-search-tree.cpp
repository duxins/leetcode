//  98. Validate Binary Search Tree
//  
//  Given a binary tree, determine if it is a valid binary search tree (BST).
//  Assume a BST is defined as follows:
//  The left subtree of a node contains only nodes with keys less than the node's key.
//  The right subtree of a node contains only nodes with keys greater than the node's key.
//  Both the left and right subtrees must also be binary search trees.
//
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/validate-binary-search-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
private:
    bool _isValidBST(TreeNode* root, long min, long max){
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min) return false;
        return _isValidBST(root->left, min, root->val) && _isValidBST(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

TEST(leetcode_098_validate_binary_search_tree, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isValidBST(tree_init({"1", "#", "2"})));
    EXPECT_TRUE(solution->isValidBST(tree_init({"2", "1", "#", "0"})));

    EXPECT_FALSE(solution->isValidBST(tree_init({"1", "1"})));
    EXPECT_FALSE(solution->isValidBST(tree_init({"2", "1", "1"})));

    EXPECT_FALSE(solution->isValidBST(tree_init({"2", "#", "3", "1"})));
    EXPECT_FALSE(solution->isValidBST(tree_init({"2", "1", "#", "0", "2"})));

    EXPECT_TRUE(solution->isValidBST(tree_init({"2147483647"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
