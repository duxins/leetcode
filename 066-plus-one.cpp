//  66. Plus One
//  
//  Given a non-negative number represented as an array of digits, plus one to the number.
//  The digits are stored such that the most significant digit is at the head of the list.
//  Subscribe to see which companies asked this question
//  
//  Tags: Array, Math
//  
//  https://leetcode.com/problems/plus-one/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        int index = digits.size() - 1;

        while(index >= 0){
            int sum = carry + digits[index--];
            result.insert(result.begin(), sum % 10);
            carry = sum / 10;
        }

        if(carry){
            result.insert(result.begin(), carry);
        }

        return result;
    }
};

TEST(leetcode_066_plus_one, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums {9};
    vector<int> result = solution->plusOne(nums);
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(1, result[0]);
    EXPECT_EQ(0, result[1]);

    nums = {1, 2};
    result = solution->plusOne(nums);
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(1, result[0]);
    EXPECT_EQ(3, result[1]);

    nums = {1, 9};
    result = solution->plusOne(nums);
    EXPECT_EQ(2, result.size());
    EXPECT_EQ(2, result[0]);
    EXPECT_EQ(0, result[1]);

    nums = {9, 9};
    result = solution->plusOne(nums);
    EXPECT_EQ(3, result.size());
    EXPECT_EQ(1, result[0]);
    EXPECT_EQ(0, result[1]);
    EXPECT_EQ(0, result[2]);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
