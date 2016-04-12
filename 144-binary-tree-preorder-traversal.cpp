//  144. Binary Tree Preorder Traversal
//  
//  Given a binary tree, return the preorder traversal of its nodes' values.
//
//  For example:
//  Given binary tree {1,#,2,3},
//  1
//   \
//    2
//   /
//  3
//  return [1,2,3].
//  Note: Recursive solution is trivial, could you do it iteratively?
//
//  Tags: Tree, Stack
//  
//  https://leetcode.com/problems/binary-tree-preorder-traversal/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *>s;
        if(root == NULL) return result;
        s.push(root);
        while(!s.empty()){
            TreeNode *n = s.top();
            s.pop();
            result.push_back(n->val);
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);
        }
        return result;
    }
};

TEST(leetcode_144_binary_tree_preorder_traversal, Basic)
{
    Solution *solution = new Solution();
    vector<int> excepted = {3, 1, 2};
    EXPECT_EQ(excepted, solution->preorderTraversal(tree_init({"3", "1", "2"})));
    excepted = {1, 4, 2, 3};
    EXPECT_EQ(excepted, solution->preorderTraversal(tree_init({"1", "4", "3", "2"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
