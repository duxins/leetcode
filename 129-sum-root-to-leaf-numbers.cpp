//  129. Sum Root to Leaf Numbers
//  
//  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//  An example is the root-to-leaf path 1->2->3 which represents the number 123.
//  Find the total sum of all root-to-leaf numbers.
//
//  For example,
//    1
//   / \
//  2   3
//
//  The root-to-leaf path 1->2 represents the number 12.
//  The root-to-leaf path 1->3 represents the number 13.
//  Return the sum = 12 + 13 = 25.
//
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/sum-root-to-leaf-numbers/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
private:
    int _sumNumbers(TreeNode *root, int sum){
       if(root == NULL) return 0;
       sum = sum * 10 + root->val;
       if(root->left == NULL && root->right == NULL){
           return sum;
       }
       return _sumNumbers(root->left, sum) + _sumNumbers(root->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return _sumNumbers(root, 0);
    }
};

TEST(leetcode_129_sum_root_to_leaf_numbers, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(25, solution->sumNumbers(tree_init({"1", "2", "3"})));
    EXPECT_EQ(10, solution->sumNumbers(tree_init({"1", "0"})));
    EXPECT_EQ(137, solution->sumNumbers(tree_init({"1", "2", "3", "4"})));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
