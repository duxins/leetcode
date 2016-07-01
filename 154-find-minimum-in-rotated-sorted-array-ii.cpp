//  154. Find Minimum in Rotated Sorted Array II
//  
//  Follow up for "Find Minimum in Rotated Sorted Array":
//  What if duplicates are allowed?
//  Would this affect the run-time complexity? How and why?
//  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//  Find the minimum element.
//  The array may contain duplicates.
//
//  Tags: Array, Binary Search
//  
//  https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] == nums[j]){
                j--;
            }else if(nums[mid] > nums[j]){
                i = mid + 1;
            }else if(nums[i] <= nums[mid]){
                return nums[i];
            }else {
                j = mid;
            }
        }
        return nums[j];
    }
};

void judge(vector<int> input, int expected){
    Solution solution;
    EXPECT_EQ(expected, solution.findMin(input));
}

TEST(leetcode_154_find_minimum_in_rotated_sorted_array_ii, Basic)
{
    judge({1}, 1);
    judge({1, 3}, 1);
    judge({5, 1, 3}, 1);
    judge({4, 5, 6, 7, 0, 1, 2}, 0);
    judge({0, 0 , 0, 0, 0}, 0);
    judge({4,5,6,7,0,1,2}, 0);
    judge({2,2,2,0,2,2}, 0);
    judge({3,3,3,3,3,3,3,3,1,3}, 1);
    judge({3,4,4,4,4,4,4,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,10,10,10,-10,-10,-10,-9,-8,-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-1,-1,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3}, -10);
    judge({-9,-9,-9,-8,-8,-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-5,-5,-4,-4,-4,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,0,0,0,1,1,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,7,7,7,7,7,8,9,9,9,10,10,10,10,10,10,10,-10,-9,-9,-9,-9}, -10);
    judge({10,10,10,-10,-10,-10,-10,-9,-9,-9,-9,-9,-9,-9,-8,-8,-8,-8,-8,-8,-8,-8,-7,-7,-7,-7,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7,7,8,8,8,8,9,9,9,9,9,9,9,10,10}, -10);
    judge({6,6,6,6,6,6,7,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,-10,-10,-10,-10,-10,-9,-9,-9,-9,-8,-8,-8,-7,-7,-7,-6,-6,-5,-5,-5,-5,-5,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-3,-3,-3,-3,-3,-2,-2,-2,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,2,2,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,6,6}, -10);

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
