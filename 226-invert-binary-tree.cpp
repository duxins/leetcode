//  226. Invert Binary Tree
//  
//  Invert a binary tree.
//       4
//     /   \
//    2     7
//   / \   / \
//  1   3 6   9
//
//  to
//       4
//     /   \
//    7     2
//   / \   / \
//  9   6 3   1
//
//  Trivia:
//
//  This problem was inspired by this original tweet by Max Howell:
//  Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
//  Subscribe to see which companies asked this question
//  
//  Tags: Tree
//  
//  https://leetcode.com/problems/invert-binary-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include "tree/tree.h"
#include <stack>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }

    //Iterative solution
    TreeNode* invertTree2(TreeNode* root) {
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            if(node){
                s.push(node->left);
                s.push(node->right);

                TreeNode *tmp = node->left;
                node->left = node->right;
                node->right = tmp;
            }
        }
        return root;
    }
};

void EXPECT(vector<string> expected, vector<string> input) {
    Solution solution = Solution();
    TreeNode *expected_tree = tree_init(expected);

    TreeNode *root = tree_init(input);
    TreeNode *reverted      = solution.invertTree(root);
    EXPECT_EQ(tree_to_vector(expected_tree), tree_to_vector(reverted));

    TreeNode *root2 = tree_init(input);
    TreeNode *reverted2     = solution.invertTree2(root2);
    EXPECT_EQ(tree_to_vector(expected_tree), tree_to_vector(reverted2));
}


TEST(leetcode_226_invert_binary_tree, Basic)
{
    EXPECT({"4", "7", "2", "9", "6", "3", "1"}, {"4", "2", "7", "1", "3", "6", "9"});
    EXPECT({"37","-48","-34","48","-100","-100","#","#","-54","#","#","#","#","-22","-71","8"}, {"37","-34","-48","#","-100","-100","48","#","#","#","#","-54","#","-71","-22","#","#","#","8"});
    EXPECT({"5","#","2","3","4","#","#","#","1"}, {"5","2","#","4","3","1"});

    EXPECT({"-64","18","12","76","#","-53","-4","3","-93","#","#","-51","#","53","3","#","47","-31","#","11",
            "-60","-44","-51","#","4","33","-81","74","60","27","-31","-81","26","-64","-35","#","78","#","#",
            "#","#","#","#","#","#","#","67","-51","-11","-49","-59","#","-24","12","47","-38","8","#","#",
            "#","#","#","#","#","-4","17","-70","#","#","#","72","-55","10","-19","-37","#","-67","#","#",
            "#","#","37","-34","90","#","#","-30","-90","48","#","-91","-88","44","80","3","#","#","#","#",
            "-53","-88","-65","56","#","-77","-17","#","72","34","67","-18","#","#","-96","-31","-85","-31",
            "-38","73","#","#","#","#","#","-67","#","#","#","#","#","#","-27","72","92","#","#","#","#",
            "24","-26","70","-40","98","#","#","-42","81","#","86","-33","#","#","-84","39","#","#","#","#",
            "#","#","#","-98","-1","-92","#","#","#","43","#","#","-72","#","-36","-66","-54","#","#","#","#",
            "#","98","#","#","#","-93"},

           {"-64","12","18","-4","-53","#","76","#","-51","#","#","-93","3","#","-31","47","#","3","53","-81",
            "33","4","#","-51","-44","-60","11","#","#","#","#","78","#","-35","-64","26","-81","-31","27","60",
            "74","#","#","8","-38","47","12","-24","#","-59","-49","-11","-51","67","#","#","#","#","#","#","#",
            "-67","#","-37","-19","10","-55","72","#","#","#","-70","17","-4","#","#","#","#","#","#","#","3",
            "80","44","-88","-91","#","48","-90","-30","#","#","90","-34","37","#","#","73","-38","-31","-85",
            "-31","-96","#","#","-18","67","34","72","#","-17","-77","#","56","-65","-88","-53","#","#","#",
            "-33","86","#","81","-42","#","#","98","-40","70","-26","24","#","#","#","#","92","72","-27","#",
            "#","#","#","#","#","-67","#","#","#","#","#","#","#","-54","-66","-36","#","-72","#","#","43","#",
            "#","#","-92","-1","-98","#","#","#","#","#","#","#","39","-84","#","#","#","#","#","#","#","#","#",
            "#","#","#","#","-93","#","#","#","98"}
    );

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
