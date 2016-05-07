//  235. Lowest Common Ancestor of a Binary Search Tree
//  
//  Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
//
//  According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor):
//  “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as
//  descendants (where we allow a node to be a descendant of itself).”
//
//        ____6____
//       /         \
//    __2__       __8__
//   /     \     /     \
//  0       4   7       9
//         / \
//        3   5
//
//  For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
//  since a node can be a descendant of itself according to the LCA definition.
//
//  Tags: Tree
//  
//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL) return NULL;

        if(root->val > max(p->val, q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }else if(root->val < min(p->val, q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

TEST(leetcode_235_lowest_common_ancestor_of_a_binary_search_tree, Basic)
{
    Solution *solution = new Solution();

//        ____6____
//       /         \
//    __2__       __8__
//   /     \     /     \
//  0       4   7       9
//         / \
//        3   5

    TreeNode *root = tree_init({"6", "2", "8", "0", "4", "7", "9", "#", "3", "5"});
    TreeNode *p = root->left; // 2;
    TreeNode *q = root->right; // 8;
    EXPECT_EQ(6, solution->lowestCommonAncestor(root, p, q)->val);

    p = root;
    q = root;
    EXPECT_EQ(6, solution->lowestCommonAncestor(root, p, q)->val);

    p = root->left->right;          // 4;
    q = root->right->left;          // 7;
    EXPECT_EQ(6, solution->lowestCommonAncestor(root, p, q)->val);

    p = root->left->left;           // 0;
    q = root->left->right;          // 4;
    EXPECT_EQ(2, solution->lowestCommonAncestor(root, p, q)->val);

    p = root->left->right->left;    // 3;
    q = root->right->left;          // 7;
    EXPECT_EQ(6, solution->lowestCommonAncestor(root, p, q)->val);

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
