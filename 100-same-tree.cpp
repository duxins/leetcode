//  100. Same Tree
//  
//  Given two binary trees, write a function to check if they are equal or not.
//  Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
//
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/same-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>
#include <stack>

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == q) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    //Iterative solution
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> sp;
        stack<TreeNode *> sq;

        if(p) sp.push(p);
        if(q) sq.push(q);

        while(!sp.empty() && !sq.empty()){
            TreeNode *m = sp.top();
            TreeNode *n = sq.top();
            sp.pop();
            sq.pop();

            if(m->val != n->val) return false;

            if(m->left && n->left) {
                sp.push(m->left);
                sq.push(n->left);
            }else if(m->left || n->left){
                return false;
            }

            if(m->right && n->right) {
                sp.push(m->right);
                sq.push(n->right);
            }else if(m->right || n->right){
                return false;
            }

        }

        return sp.size() == sq.size();
    }
};

TEST(leetcode_100_same_tree, Basic)
{
    Solution *solution = new Solution();
    TreeNode *t1 = tree_init({"1", "2", "3", "#", "#", "4"});
    TreeNode *t2 = tree_init({"1", "2", "3", "#", "#", "4"});

    TreeNode *t3 = tree_init({"1", "2", "3", "#", "#", "5"});

    EXPECT_TRUE(solution->isSameTree(t1, t2));
    EXPECT_FALSE(solution->isSameTree(t1, t3));

    EXPECT_TRUE(solution->isSameTree2(t1, t2));
    EXPECT_FALSE(solution->isSameTree2(t1, t3));
}

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));
    const time_t t = time(NULL);
    cout << t << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
