//  26. Remove Duplicates from Sorted Array
//  
//  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//  Do not allocate extra space for another array, you must do this in place with constant memory.
//  For example,
//  Given input array nums = [1,1,2],
//  Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
//  Subscribe to see which companies asked this question
//  
//  Tags: Array, Two Pointers
//  
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

TEST(leetcode_026_remove_duplicates_from_sorted_array, Basic)
{
    Solution *s = new Solution();
    vector<int> nums{1, 1, 2, 3, 4};
    int len = s->removeDuplicates(nums);
    EXPECT_EQ(4, len);
    EXPECT_EQ(1, nums[0]);
    EXPECT_EQ(2, nums[1]);
    EXPECT_EQ(3, nums[2]);
    EXPECT_EQ(4, nums[3]);

    nums = {1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 5};
    len = s->removeDuplicates(nums);
    EXPECT_EQ(5, len);
    EXPECT_EQ(1, nums[0]);
    EXPECT_EQ(2, nums[1]);
    EXPECT_EQ(3, nums[2]);
    EXPECT_EQ(4, nums[3]);
    EXPECT_EQ(5, nums[4]);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
