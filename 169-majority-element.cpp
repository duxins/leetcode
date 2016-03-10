//  169. Majority Element
//  
//  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//  You may assume that the array is non-empty and the majority element always exist in the array.
//  Credits:Special thanks to @ts for adding this problem and creating all test cases.
//
//  Tags: Divide and Conquer, Array, Bit Manipulation
//  
//  https://leetcode.com/problems/majority-element/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElementBit(vector<int>& nums) {
        int result = 0;
        int mask = 1;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int bits = 0;
            for (int j = 0; j < n; ++j) {
                if(nums[j] & mask) bits++;
            }

            if(bits > n /2){
                result |= mask;
            }

            mask <<= 1;
        }
        return result;
    }
};

TEST(leetcode_169_majority_element, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums {1, 2, 2, 2, 3};
    EXPECT_EQ(2, solution->majorityElement(nums));
}

TEST(leetcode_169_majority_element, Bit)
{
    Solution *solution = new Solution();
    vector<int> nums {8, 8, 8, 0, 0};
    EXPECT_EQ(8, solution->majorityElementBit(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
