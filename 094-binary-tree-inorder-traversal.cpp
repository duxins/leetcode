//  94. Binary Tree Inorder Traversal
//  
//  Given a binary tree, return the inorder traversal of its nodes' values.
//  For example:
//  Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
//  return [1,3,2].
//
//  Note: Recursive solution is trivial, could you do it iteratively?
//
//
//  Tags: Tree, Hash Table, Stack
//  
//  https://leetcode.com/problems/binary-tree-inorder-traversal/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *>s;
        if(root == NULL) return result;
        TreeNode *node = root;
        while(node != NULL || !s.empty()){
            if(node){
                s.push(node);
                node = node->left;
            }else{
                node = s.top();
                s.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};

TEST(leetcode_094_binary_tree_inorder_traversal, Basic)
{
    Solution *solution = new Solution();
    vector<int> expected = {1, 3, 2};
    EXPECT_EQ(expected, solution->inorderTraversal(tree_init({"1", "#", "2", "3"})));
    expected = {2, 1};
    EXPECT_EQ(expected, solution->inorderTraversal(tree_init({"1", "2"})));
    expected = {2, 1, 3};
    EXPECT_EQ(expected, solution->inorderTraversal(tree_init({"1", "2", "3"})));
    expected = {2, 1, 6, 4, 3, 5};
    EXPECT_EQ(expected, solution->inorderTraversal(tree_init({"1", "2", "3", "#", "#", "4", "5", "6"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
