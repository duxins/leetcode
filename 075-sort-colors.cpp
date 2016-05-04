//  75. Sort Colors
//  
//  Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//  Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//  Note:
//  You are not suppose to use the library's sort function for this problem.
//  click to show follow up.
//
//  Follow up:
//  A rather straight forward solution is a two-pass algorithm using counting sort.
//  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//  Could you come up with an one-pass algorithm using only constant space?
//
//  Tags: Array, Two Pointers, Sort
//  
//  https://leetcode.com/problems/sort-colors/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() -1, mid = 0;
        while(mid <= j ){
            if(nums[mid] == 0){
                swap(nums[mid++], nums[i++]);
            }else if(nums[mid] == 2){
                swap(nums[mid], nums[j--]);
            }else{
                mid++;
            }
        }
    }
};


TEST(leetcode_075_sort_colors, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1, 1, 1, 0, 0, 2, 2};
    vector<int> expected = {0, 0, 1, 1, 1, 2, 2};
    solution->sortColors(nums);
    EXPECT_EQ(expected, nums);

    nums = {1, 0};
    expected = {0, 1};
    solution->sortColors(nums);
    EXPECT_EQ(expected, nums);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
