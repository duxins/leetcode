//  102. Binary Tree Level Order Traversal
//  
//  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//  For example:

//  Given binary tree {3,9,20,#,#,15,7},
//   3
//  / \
// 9  20
//   /  \
//  15   7
//  return its level order traversal as:

//  [
//  [3],
//  [9,20],
//  [15,7]
//  ]
//
//  Tags: Tree, Breadth-first Search
//  
//  https://leetcode.com/problems/binary-tree-level-order-traversal/    

#include <iostream>
#include <gtest/gtest.h>
#include <queue>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            vector<int>row;
            int size = q.size();
            for(int i = 0; i < size; i ++){
                TreeNode *n = q.front();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                row.push_back(n->val);
                q.pop();
            }
            result.push_back(row);
        }
        return result;
    }
};


TEST(leetcode_102_binary_tree_level_order_traversal, Basic)
{
    Solution *solution = new Solution();
    vector<vector<int>> expected = {{3}, {9, 20}, {15, 7}};
    EXPECT_EQ(expected, solution->levelOrder(tree_init({"3", "9", "20" , "#", "#", "15" ,"7"})));
    expected = {{1}, {2}, {3}, {4, 5}};
    EXPECT_EQ(expected, solution->levelOrder(tree_init({"1", "#", "2" , "#", "3", "4" ,"5"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
