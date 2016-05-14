//  260. Single Number III
//  
//  Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
//  exactly twice. Find the two elements that appear only once.
//
//  For example:
//
//  Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//  Note:
//  The order of the result is not important. So in the above example, [5, 3] is also correct.
//  Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/single-number-iii/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int x = 0, a = 0 , b = 0;

        for(int n : nums){
            x ^= n;
        }

        int diff = x & (~(x - 1));

        for(int n : nums){
            if ((diff & n) != 0){
                a ^= n;
            } else {
                b ^= n;
            }
        }

        result[0] = a;
        result[1] = b;

        return result;
    }
};

void EXPECT(vector<int> expected, vector<int>result){
    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

TEST(leetcode_260_single_number_iii, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    EXPECT({3, 5}, solution->singleNumber(nums));

    nums = {-1, -2, -1, -3, -2, -5};
    EXPECT({-3, -5}, solution->singleNumber(nums));

    nums = {-1, -2, -1, -3, -2, -5};
    EXPECT({-3, -5}, solution->singleNumber(nums));

    nums = {0, 0, INT_MAX, INT_MIN, 1, 1};
    EXPECT({INT_MAX, INT_MIN}, solution->singleNumber(nums));
}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
