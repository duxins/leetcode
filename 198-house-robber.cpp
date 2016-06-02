//  198. House Robber
//  
//  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
//  the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
//  and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//  Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
//  of money you can rob tonight without alerting the police.
//
//  Tags: Dynamic Programming
//  
//  https://leetcode.com/problems/house-robber/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        nums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            nums[i] = max(nums[i] + nums[i-2], nums[i-1]);
        }
        return nums[nums.size() - 1];
    }
};

TEST(leetcode_198_house_robber, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
    EXPECT_EQ(42, solution->rob(nums));

    nums = {1};
    EXPECT_EQ(1, solution->rob(nums));

    nums = {1, 2};
    EXPECT_EQ(2, solution->rob(nums));

    nums = {1, 2, 3};
    EXPECT_EQ(4, solution->rob(nums));

    nums = {1, 2, 3, 4};
    EXPECT_EQ(6, solution->rob(nums));

    nums = {2, 1, 1, 1};
    EXPECT_EQ(3, solution->rob(nums));

    nums = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    EXPECT_EQ(3365, solution->rob(nums));

    nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
    EXPECT_EQ(4173, solution->rob(nums));

    nums = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
    EXPECT_EQ(7102, solution->rob(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
