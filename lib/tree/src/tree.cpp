//
// Created by Xin Du on 4/5/16.
//

#include "tree/tree.h"
#include <queue>
#include <algorithm>

//Taken from http://stackoverflow.com/q/23754060/575163
TreeNode *tree_init(std::vector<std::string> nodes){
    std::queue<TreeNode *> q;
    if(nodes.size() == 0) return NULL;
    TreeNode *root = new TreeNode(std::stoi(nodes[0]));
    q.push(root);

    TreeNode *cur = NULL;
    bool is_left = true;

    for(int i = 1; i < nodes.size(); i++){
        TreeNode *node = NULL;
        if(nodes[i] != "#") {
            node = new TreeNode(std::stoi(nodes[i]));
            q.push(node);
        }

        if(is_left){
            cur = q.front();
            q.pop();
            cur->left = node;
            is_left = false;
        }else{
            cur->right = node;
            is_left = true;
        }

    }

    return root;

}

bool tree_equal(TreeNode *p, TreeNode *q) {
    if(p == q) return true;
    if(p == NULL || q == NULL) return false;
    if(p->val != q->val) return false;
    return tree_equal(p->left, q->left) && tree_equal(p->right, q->right);
}

int tree_height(TreeNode *root) {
    if(root == NULL) return 0;
    return 1 + std::max(tree_height(root->left), tree_height(root->right));
}

std::vector<std::string> tree_to_vector(TreeNode *root){
    std::vector<std::string> result;
    if(root == NULL) return result;
    std::queue<TreeNode *>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i ++){
            TreeNode *n = q.front();
            if(n == NULL){
                result.push_back("#");
            }else{
                q.push(n->left);
                q.push(n->right);
                result.push_back(std::to_string(n->val));
            }
            q.pop();
        }
    }

    //Remove trailing '#'
    auto it = result.end();
    while(it > result.begin()){
        it--;
        if(*it != "#"){
            break;
        }else{
            it = result.erase(it);
        }
    }

    return result;
}


