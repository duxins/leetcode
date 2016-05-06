//  114. Flatten Binary Tree to Linked List
//  
//  Given a binary tree, flatten it to a linked list in-place.
//
//  For example,
//  Given
//
//      1
//     / \
//    2   5
//   / \   \
//  3   4   6
//
//  The flattened tree should look like:
//
//  1
//   \
//    2
//     \
//      3
//       \
//        4
//         \
//          5
//           \
//            6
//
//  Hints:
//  If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
//
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        stack<TreeNode *>s;
        s.push(root);

        TreeNode *prev = NULL;

        while(!s.empty()){
            TreeNode *n = s.top();
            s.pop();
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);

            if(prev == NULL) {
                prev = n;
            } else{
                prev->right = n;
                prev->left = NULL;
                prev = n;
            }
        }

    }
};


TEST(leetcode_114_flatten_binary_tree_to_linked_list, Basic)
{
    Solution *solution = new Solution();

    TreeNode *root = tree_init({"0", "1"});
    TreeNode *expected = tree_init({"0", "#", "1"});
    solution->flatten(root);
    EXPECT_TRUE(tree_equal(expected, root));

    root = tree_init({"1", "2", "5", "3", "4", "#", "6"});
    expected = tree_init({"1", "#", "2", "#", "3", "#", "4", "#", "5", "#", "6"});
    solution->flatten(root);
    EXPECT_TRUE(tree_equal(expected, root));

    root = tree_init({"0"});
    expected = tree_init({"0"});
    solution->flatten(root);
    EXPECT_TRUE(tree_equal(expected, root));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
