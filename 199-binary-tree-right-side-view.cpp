//  199. Binary Tree Right Side View
//  
//  Given a binary tree, imagine yourself standing on the right side of it,
//  return the values of the nodes you can see ordered from top to bottom.
//
//  For example:
//  Given the following binary tree,
//
//     1
//   /   \
//  2     3
//   \     \
//    5     4
//
//  You should return [1, 3, 4].
//
//  Tags: Tree, Depth-first Search, Breadth-first Search
//  
//  https://leetcode.com/problems/binary-tree-right-side-view/    

#include <iostream>
#include <gtest/gtest.h>
#include <queue>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        queue<TreeNode*>q;
        if(!root)return result;

        q.push(root);

        while(!q.empty()){
            result.push_back(q.front()->val);

            int size = q.size();

            while(size > 0){
                if(q.front()->right) q.push(q.front()->right);
                if(q.front()->left)  q.push(q.front()->left);
                q.pop();
                size--;
            }

        }

        return result;
    }
};


TEST(leetcode_199_binary_tree_right_side_view, Basic)
{
    Solution *solution = new Solution();
    vector<int> expected = {1, 3, 4};
    EXPECT_EQ(expected, solution->rightSideView(tree_init({"1", "2", "3", "#", "5", "#", "4"})));
//
//     1
//    / \
//   2   3
//    \
//     5
//      \
//       6

    expected = {1, 3, 5, 6};
    EXPECT_EQ(expected, solution->rightSideView(tree_init({"1", "2", "3", "#", "5", "#", "#", "6"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
