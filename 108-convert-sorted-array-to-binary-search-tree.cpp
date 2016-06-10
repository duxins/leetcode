//  108. Convert Sorted Array to Binary Search Tree
//  
//  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//  Tags: Tree, Depth-first Search
//  
//  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/    

#include <iostream>
#include <gtest/gtest.h>
#include <tree/tree.h>
#include <vector>

using namespace std;

class Solution {
private:
    TreeNode* _sortedArrayToBST(int left, int right, vector<int>& nums) {
        if (left > right) return NULL;

        int mid = (left + right) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = _sortedArrayToBST(left, mid - 1, nums);
        root->right = _sortedArrayToBST(mid + 1, right, nums);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(0, nums.size() - 1, nums);
    }
};

void EXPECT(vector<string> expected, vector<int> nums){
    Solution *solution = new Solution();
    TreeNode *result = solution->sortedArrayToBST(nums);
    EXPECT_EQ(expected, tree_to_vector(result));
}

TEST(leetcode_108_convert_sorted_array_to_binary_search_tree, Basic)
{
    EXPECT({"3", "1", "5", "0", "2", "4", "6"}, {0, 1, 2, 3, 4, 5, 6});
    EXPECT({"4", "1", "7", "0", "2", "5", "8", "#", "#", "#", "3", "#", "6", "#", "9"}, {0,1,2,3,4,5,6,7,8,9});
    EXPECT({"4", "1", "7", "0", "2", "5", "8", "#", "#", "#", "3", "#", "6", "#", "9"}, {0,1,2,3,4,5,6,7,8,9});
    EXPECT({"20", "-76", "70", "-89", "-53", "41", "88", "-93", "-85", "-56", "-20", "28", "50", "87", "91", "#", "#", "#", "#", "#", "#", "#", "-10", "#", "#", "#", "66", "#", "#", "#", "94"},
           {-93,-89,-85,-76,-56,-53,-20,-10,20,28,41,50,66,70,87,88,91,94});
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
