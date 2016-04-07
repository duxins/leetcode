//  219. Contains Duplicate II
//  
//  Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
//  such that nums[i] = nums[j] and the difference between i and j is at most k.
//
//  Tags: Array, Hash Table
//  
//  https://leetcode.com/problems/contains-duplicate-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(m.find(num) == m.end()){
                m[num] = i;
            }else if(i - m[num] > k){
                m[num] = i;
            }else{
                return true;
            }
        }
        return false;
    }
};

TEST(leetcode_219_contains_duplicate_ii, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums;

    nums = {1, 2, 3, 4, 2};
    EXPECT_TRUE(solution->containsNearbyDuplicate(nums,3));
    EXPECT_FALSE(solution->containsNearbyDuplicate(nums,2));

    nums =  {1, 2, 3, 4, 5};
    EXPECT_FALSE(solution->containsNearbyDuplicate(nums,5));

    nums = {1, 1};
    EXPECT_FALSE(solution->containsNearbyDuplicate(nums,0));
    EXPECT_TRUE(solution->containsNearbyDuplicate(nums,1));

    nums = {1};
    EXPECT_FALSE(solution->containsNearbyDuplicate(nums,10));

    nums = {};
    EXPECT_FALSE(solution->containsNearbyDuplicate(nums,10));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
