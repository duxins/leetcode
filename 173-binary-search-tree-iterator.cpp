//  173. Binary Search Tree Iterator
//  
//  Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//  Calling next() will return the next smallest number in the BST.
//  Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
//  Your BSTIterator will be called like this:
//
//  BSTIterator i = BSTIterator(root);
//  while (i.hasNext()) cout << i.next();
//
//  Tags: Tree, Stack, Design
//  
//  https://leetcode.com/problems/binary-search-tree-iterator/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>
#include <stack>

using namespace std;

class BSTIterator {
private:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = s.top();
        int num = node->val;
        s.pop();

        node = node->right;
        while(node){
            s.push(node);
            node = node->left;
        }

        return num;

    }
};

void judge(TreeNode *input, vector<int> expected){
    BSTIterator i = BSTIterator(input);
    vector<int> v;
    while(i.hasNext()){
        v.push_back(i.next());
    }
    EXPECT_EQ(expected, v);
}


TEST(leetcode_173_binary_search_tree_iterator, Basic)
{
    judge(tree_init({"1"}), {1});

    judge(tree_init({"1", "#", "2"}), {1, 2});

    judge(tree_init({"2", "1"}),{1, 2});

    judge(tree_init({"3", "2", "4", "1"}), {1, 2, 3, 4});

    judge(tree_init({"44","20","49","14","28","47","#","12","15","25","41","45","48","4","13","#","16","22","27","31",
                     "43","#","46","#","#","3","9","#","#","#","17","21","23","26","#","29","36","42","#","#","#","0","#",
                     "7","11","#","18","#","#","#","24","#","#","#","30","34","39","#","#","#","2","5","8","10","#","#",
                     "19","#","#","#","#","32","35","38","40","1","#","#","6","#","#","#","#","#","#","#","33","#","#","37"}),
          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}
    );

    judge(tree_init({"41","37","44","24","39","42","48","1","35","38","40","#","43","46","49","0","2","30","36","#","#",
                     "#","#","#","#","45","47","#","#","#","#","#","4","29","32","#","#","#","#","#","#","3","9","26","#",
                     "31","34","#","#","7","11","25","27","#","#","33","#","6","8","10","16","#","#","#","28","#","#","5",
                     "#","#","#","#","#","15","19","#","#","#","#","12","#","18","20","#","13","17","#","#","22","#","14",
                     "#","#","21","23"}),
          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}
    );

    judge(tree_init({"45","30","46","10","36","#","49","8","24","34","42","48","#","4","9","14","25","31","35","41","43",
                     "47","#","0","6","#","#","11","20","#","28","#","33","#","#","37","#","#","44","#","#","#","1","5",
                     "7","#","12","19","21","26","29","32","#","#","38","#","#","#","3","#","#","#","#","#","13","18","#",
                     "#","22","#","27","#","#","#","#","#","39","2","#","#","#","15","#","#","23","#","#","#","40","#","#",
                     "#","16","#","#","#","#","#","17"}),
          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}
    );
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
