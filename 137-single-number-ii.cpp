//  137. Single Number II
//  
//  Given an array of integers, every element appears three times except for one. Find that single one.
//  Note:
//  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/single-number-ii/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            for(auto a: nums){
                bits[i] += (a >> i) & 1;
            }
        }
        for (int j = 0; j < 32; ++j) {
            if(bits[j] % 3 != 0){
                result |= (1 << j);
            }
        }
        return result;
    }
};


TEST(leetcode_137_single_number_ii, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4};
    EXPECT_EQ(3, solution->singleNumber(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
