//  1. Two Sum
//  
//  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//  You may assume that each input would have exactly one solution.
//
//  Example:
//      Given nums = [2, 7, 11, 15], target = 9,
//      Because nums[0] + nums[1] = 2 + 7 = 9,
//      return [0, 1].
//
//  UPDATE (2016/2/13):
//      The return format had been changed to zero-based indices. Please read the above updated description carefully.
//
//  Tags: Array, Hash Table
//  
//  https://leetcode.com/problems/two-sum/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if(m.find(nums[i]) != m.end()){
                result = {m[nums[i]], i};
                return result;
            }
            m[target-nums[i]] = i;
        }
        return result;
    }
};

TEST(leetcode_001_two_sum, Basic)
{
    Solution *solution = new Solution();
    vector<int> num {2, 7, 11, 15};
    vector<int> result = solution->twoSum(num, 9);
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(0, result[0]);
    EXPECT_EQ(1, result[1]);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
