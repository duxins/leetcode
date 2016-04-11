//  268. Missing Number
//  
//  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//  For example,
//
//  Given nums = [0, 1, 3] return 2.
//
//  Note:
//  Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
//
//  Tags: Array, Math, Bit Manipulation
//  
//  https://leetcode.com/problems/missing-number/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        for(auto c : nums){
            total -= c;
        }
        return total;
    }
};

TEST(leetcode_268_missing_number, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {0, 1};
    EXPECT_EQ(2, solution->missingNumber(nums));
    nums = {0, 1, 3};
    EXPECT_EQ(2, solution->missingNumber(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
