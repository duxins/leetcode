//  230. Kth Smallest Element in a BST
//  
//  Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//  Note: 
//  You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//  Follow up:
//  What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
//  How would you optimize the kthSmallest routine?
//  Try to utilize the property of a BST.
//  What if you could modify the BST node's structure?
//  The optimal runtime complexity is O(height of BST).
//
//  Tags: Binary Search, Tree
//  
//  https://leetcode.com/problems/kth-smallest-element-in-a-bst/    

#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <tree/tree.h>

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if(--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return 0;
    }
};

TEST(leetcode_230_kth_smallest_element_in_a_bst, Basic)
{
    Solution *solution = new Solution();
    TreeNode *root = tree_init({"1","#","2","#", "3"});

    EXPECT_EQ(1, solution->kthSmallest(root, 1));
    EXPECT_EQ(2, solution->kthSmallest(root, 2));
    EXPECT_EQ(3, solution->kthSmallest(root, 3));

    root = tree_init({"4","2","5","1", "3", "#", "6"});
    EXPECT_EQ(1, solution->kthSmallest(root, 1));
    EXPECT_EQ(4, solution->kthSmallest(root, 4));
    EXPECT_EQ(5, solution->kthSmallest(root, 5));
    EXPECT_EQ(6, solution->kthSmallest(root, 6));

    root = tree_init({"1","0","39","#","#","7","40","6","22","#","48","3","#","16","23","45","49","2","5","12","21","#",
                      "33","44","47","#","#","#","#","4","#","10","13","19","#","27","38","43","#","46","#","#","#","8",
                      "11","#","14","17","20","25","30","34","#","41","#","#","#","#","9","#","#","#","15","#","18","#",
                      "#","24","26","29","31","#","37","#","42","#","#","#","#","#","#","#","#","#","#","28","#","#","32",
                      "35","#","#","#","#","#","#","#","#","36"});

    EXPECT_EQ(9,  solution->kthSmallest(root, 10));
    EXPECT_EQ(17, solution->kthSmallest(root, 18));
    EXPECT_EQ(31, solution->kthSmallest(root, 32));
    EXPECT_EQ(46, solution->kthSmallest(root, 47));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
