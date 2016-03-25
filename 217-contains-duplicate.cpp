//  217. Contains Duplicate
//  
//  Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
//  Subscribe to see which companies asked this question
//  
//  Tags: Array, Hash Table
//  
//  https://leetcode.com/problems/contains-duplicate/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto n: nums) {
            if(m.find(n) != m.end()) return true;
            m[n] = true;
        }
        return false;
    }
};

TEST(leetcode_217_contains_duplicate, Basic)
{
    vector<int>nums {1, 2, 3, 4, 4};;
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->containsDuplicate(nums));

    nums = {1, 2, 3, 4};
    EXPECT_FALSE(solution->containsDuplicate(nums));

    nums = {1, 1};
    EXPECT_TRUE(solution->containsDuplicate(nums));

    nums = {1};
    EXPECT_FALSE(solution->containsDuplicate(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
