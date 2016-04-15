//  107. Binary Tree Level Order Traversal II
//  
//  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//  For example:
//  Given binary tree {3,9,20,#,#,15,7},
//
//    3
//   / \
//  9  20
//   /  \
//  15   7
//  return its bottom-up level order traversal as:
//
//  [
//  [15,7],
//  [9,20],
//  [3]
//  ]
//
//  Tags: Tree, Breadth-first Search
//  
//  https://leetcode.com/problems/binary-tree-level-order-traversal-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>
#include <queue>

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *>q;
        if(root == NULL) return result;
        q.push(root);
        while(!q.empty()){
            vector<int> row;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *n = q.front();
                q.pop();
                row.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            result.push_back(row);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


TEST(leetcode_107_binary_tree_level_order_traversal_ii, Basic)
{
    Solution *solution = new Solution();
    vector<vector<int>> expected = {{15, 7}, {9, 20}, {3}};
    EXPECT_EQ(expected, solution->levelOrderBottom(tree_init({"3","9","20","#","#","15","7"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
