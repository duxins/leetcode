//  303. Range Sum Query - Immutable
//  
//  Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//  Example:
//  Given nums = [-2, 0, 3, -5, 2, -1]
//  sumRange(0, 2) -> 1
//  sumRange(2, 5) -> -1
//  sumRange(0, 5) -> -3
//  Note:
//  You may assume that the array does not change.
//  There are many calls to sumRange function.
//
//  Tags: Dynamic Programming
//  
//  https://leetcode.com/problems/range-sum-query-immutable/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        vector<int> v = nums;
        for(int i = 1; i < nums.size(); i++){
            v[i] = v[i] + v[i-1];
        }
        sum = v;
    }

    int sumRange(int i, int j) {
        return sum[j] - (i == 0 ? 0 : sum[i - 1]);
    }
};



TEST(leetcode_303_range_sum_query_immutable, Basic)
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *arr = new NumArray(nums);
    EXPECT_EQ(1, arr->sumRange(0, 2));
    EXPECT_EQ(-1, arr->sumRange(2, 5));
    EXPECT_EQ(-3, arr->sumRange(0, 5));
    EXPECT_EQ(0, arr->sumRange(2, 4));

    nums = {1, 2};
    arr = new NumArray(nums);
    EXPECT_EQ(3, arr->sumRange(0, 1));

    nums = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};
    arr = new NumArray(nums);
    EXPECT_EQ(4830, arr->sumRange(0, 8));
    EXPECT_EQ(6383, arr->sumRange(4, 5));
    EXPECT_EQ(-15886, arr->sumRange(9, 11));
    EXPECT_EQ(-1149, arr->sumRange(0, 9));
    EXPECT_EQ(-15759, arr->sumRange(0, 12));
    EXPECT_EQ(-24293, arr->sumRange(5, 12));
    EXPECT_EQ(-14974, arr->sumRange(5, 10));
    EXPECT_EQ(5969, arr->sumRange(3, 7));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
