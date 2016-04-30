//  53. Maximum Subarray
//  
//  Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//  For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
//  the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//  click to show more practice.
//
//  More practice:
//  If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//
//  Tags: Array, Dynamic Programming, Divide and Conquer
//  
//  https://leetcode.com/problems/maximum-subarray/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(max < sum){
                max = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return max;
    }
};


TEST(leetcode_053_maximum_subarray, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(6, solution->maxSubArray(nums));
    nums = {1, 2, -3};
    EXPECT_EQ(3, solution->maxSubArray(nums));
    nums = {-2, -1, -3};
    EXPECT_EQ(-1, solution->maxSubArray(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
