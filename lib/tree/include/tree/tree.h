//
// Created by Xin Du on 4/5/16.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *tree_init(std::vector<std::string> nodes);

int tree_height(TreeNode *root);

std::vector<std::string> tree_to_vector(TreeNode *root);

bool tree_equal(TreeNode *p, TreeNode *q);

#endif //LEETCODE_TREE_H
