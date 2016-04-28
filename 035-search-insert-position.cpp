//  35. Search Insert Position
//  
//  Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//  You may assume no duplicates in the array.
//
//  Here are few examples.
//  [1,3,5,6], 5 → 2
//  [1,3,5,6], 2 → 1
//  [1,3,5,6], 7 → 4
//  [1,3,5,6], 0 → 0
//
//  Tags: Array, Binary Search
//  
//  https://leetcode.com/problems/search-insert-position/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size();
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] >= target){
                j = mid;
            }else{
                i = mid + 1;
            }
        }
        return i;
    }
};

TEST(leetcode_035_search_insert_position, Basic)
{
    Solution * solution = new Solution();
    vector<int> nums = {1, 3, 5, 6};
    EXPECT_EQ(2, solution->searchInsert(nums, 5));
    EXPECT_EQ(1, solution->searchInsert(nums, 2));
    EXPECT_EQ(4, solution->searchInsert(nums, 7));
    EXPECT_EQ(0, solution->searchInsert(nums, 0));

    nums = {1};
    EXPECT_EQ(1, solution->searchInsert(nums, 2));
    EXPECT_EQ(0, solution->searchInsert(nums, 0));

    nums = {};
    EXPECT_EQ(0, solution->searchInsert(nums, 10));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
