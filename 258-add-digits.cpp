//  258. Add Digits
//  
//  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
//
//  For example:
//      Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
//
//  Follow up:
//      Could you do it without any loop/recursion in O(1) runtime?
//      A naive implementation of the above process is trivial. Could you come up with other methods?
//      What are all the possible results?
//      How do they occur, periodically or randomly?
//      You may find this Wikipedia article useful.
//
//  Tags: Math
//  
//  https://leetcode.com/problems/add-digits/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num / 10) {
            num = num / 10 + num % 10;
        }
        return num;
    }
};

TEST(leetcode_258_add_digits, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(5, solution->addDigits(5));
    EXPECT_EQ(2, solution->addDigits(38));
    EXPECT_EQ(1, solution->addDigits(10));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
