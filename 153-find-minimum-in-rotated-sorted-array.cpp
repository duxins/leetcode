//  153. Find Minimum in Rotated Sorted Array
//  
//  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//  Find the minimum element.
//  You may assume no duplicate exists in the array.
//
//  Tags: Array, Binary Search
//  
//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int i = 0, j = nums.size() - 1;

        while(i < j){
            int mid = (i + j) / 2;

            if(nums[mid] > nums[j]){
                i = mid + 1;
            }else {
                j = mid;
            }
        }

        return nums[j];
    }
};

TEST(leetcode_153_find_minimum_in_rotated_sorted_array, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums =  {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(0, solution->findMin(nums));

    nums =  {8, 9, 10, 0, 1, 2, 3, 4, 5, 7};
    EXPECT_EQ(0, solution->findMin(nums));

    nums = {1};
    EXPECT_EQ(1, solution->findMin(nums));

    nums = {1, 0};
    EXPECT_EQ(0, solution->findMin(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
