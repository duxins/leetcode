//  283. Move Zeroes
//  
//  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//  For example, given nums  = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
//
//  Note:
//  You must do this in-place without making a copy of the array.
//  Minimize the total number of operations.
//
//  Tags: Array, Two Pointers
//  
//  https://leetcode.com/problems/move-zeroes/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0) nums[i++] = nums[j];
        }

        for (int k = i; k < nums.size(); ++k) {
            nums[k] = 0;
        }
    }
};

TEST(leetcode_283_move_zeroes, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {0, 1, 0, 3, 12};
    solution->moveZeroes(nums);
    EXPECT_EQ(1, nums[0]);
    EXPECT_EQ(3, nums[1]);
    EXPECT_EQ(12, nums[2]);
    EXPECT_EQ(0, nums[3]);
    EXPECT_EQ(0, nums[4]);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
