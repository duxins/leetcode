//  101. Symmetric Tree
//  
//  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//  For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//  But the following is not:
//   1
//  / \
//  2   2
//   \   \
//    3    3
//
//  Note:
//  Bonus points if you could solve it both recursively and iteratively.
//
//  Tags: Tree, Depth-first Search, Breadth-first Search
//  
//  https://leetcode.com/problems/symmetric-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
private:
    bool isSymmetric(TreeNode *t1, TreeNode *t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 && t2 && t1->val == t2->val){
            return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
};

TEST(leetcode_101_symmetric_tree, Recursively)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isSymmetric(tree_init({"1", "2", "2", "3", "4", "4", "3"})));
    EXPECT_FALSE(solution->isSymmetric(tree_init({"1", "2", "2", "#", "3", "#", "3"})));
}

//TODO: iteratively

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
