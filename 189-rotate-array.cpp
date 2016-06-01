//  189. Rotate Array
//  
//  Rotate an array of n elements to the right by k steps.
//  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 
//  Note:
//  Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//
//  Hint:
//  Could you do it in-place with O(1) extra space?
//
//  Tags: Array
//  
//  https://leetcode.com/problems/rotate-array/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result(nums.size());
        int size = nums.size();
        for(int i = 0 ; i < size; i++){
            if((i + k)  < size) {
                result[i + k] = nums[i];
            }else{
                result[(i + k) % size] = nums[i];
            }
        }
        nums = result;
    }
};

TEST(leetcode_189_rotate_array, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> expected = {5, 6, 7 ,1 ,2 ,3, 4};
    solution->rotate(nums, 3);
    EXPECT_EQ(expected, nums);

    nums = {1, 2, 3, 4, 5, 6, 7};
    expected = {4, 5, 6, 7, 1, 2, 3};
    solution->rotate(nums, 4);
    EXPECT_EQ(expected, nums);

    nums = {1, 2, 3, 4, 5, 6};
    expected = {2, 3, 4, 5, 6, 1};
    solution->rotate(nums, 11);
    EXPECT_EQ(expected, nums);

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    expected = {10, 11, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    solution->rotate(nums, 17);
    EXPECT_EQ(expected, nums);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
