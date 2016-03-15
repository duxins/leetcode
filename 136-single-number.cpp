//  136. Single Number
//  
//  Given an array of integers, every element appears twice except for one. Find that single one.
//  Note:
//  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//  Subscribe to see which companies asked this question
//  
//  Tags: Hash Table, Bit Manipulation
//  
//  https://leetcode.com/problems/single-number/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto i : nums){
            result ^= i;
        }
        return result;
    }
};

TEST(leetcode_136_single_number, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1, 1, 2, 2, 3};
    EXPECT_EQ(3, solution->singleNumber(nums));
    nums = {2, 2, 3, 3, 4, 5, 5};
    EXPECT_EQ(4, solution->singleNumber(nums));
    nums = {1};
    EXPECT_EQ(1, solution->singleNumber(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
