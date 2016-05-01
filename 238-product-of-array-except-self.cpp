//  238. Product of Array Except Self
//  
//  Given an array of n integers where n > 1, nums, return an array output such that output[i]
//  is equal to the product of all the elements of nums except nums[i].
//  Solve it without division and in O(n).
//  For example, given [1,2,3,4], return [24,12,8,6].
//
//  Follow up:
//  Could you solve it with constant space complexity?
//  (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
//
//  Tags: Array
//  
//  https://leetcode.com/problems/product-of-array-except-self/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int i= 0, product = 1; i<nums.size();  i++){
            result[i] = product;
            product *= nums[i];
        }
        for(int i = nums.size() - 1, product = 1; i >=0; i--){
            result[i] *= product;
            product *= nums[i];
        }
        return result;
    }
};

TEST(leetcode_238_product_of_array_except_self, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1, 2, 3, 4};
    vector<int> expected = {24, 12, 8, 6};
    EXPECT_EQ(expected, solution->productExceptSelf(nums));

    nums = {-1, 2, -3, 0};
    expected = {0, 0, 0, 6};
    EXPECT_EQ(expected, solution->productExceptSelf(nums));

    nums = {1, 2};
    expected = {2, 1};
    EXPECT_EQ(expected, solution->productExceptSelf(nums));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
