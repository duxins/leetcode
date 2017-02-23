//  
//  504. Base 7
//            
//  
//  Given an integer, return its base 7 string representation.
//
//  Example 1:
//  Input: 100
//  Output: "202"
//
//  Example 2:
//  Input: -7
//  Output: "-10"
//
//  Note:
//  The input will be in range of [-1e7, 1e7].
//  https://leetcode.com/problems/base-7/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        int n = abs(num);
        do {
            result = to_string(n%7) + result;
            n /= 7;
        } while (n);
        return  num >= 0 ? result : ("-" + result);
    }
};

TEST(leetcode_504_base_7, Basic)
{
    Solution solution;
    EXPECT_EQ("0", solution.convertToBase7(0));
    EXPECT_EQ("10", solution.convertToBase7(7));
    EXPECT_EQ("202", solution.convertToBase7(100));
    EXPECT_EQ("2160", solution.convertToBase7(777));
    EXPECT_EQ("41104", solution.convertToBase7(10000));
    EXPECT_EQ("564354", solution.convertToBase7(99999));
    EXPECT_EQ("1022634", solution.convertToBase7(123456));
    EXPECT_EQ("-10", solution.convertToBase7(-7));
    EXPECT_EQ("-41104", solution.convertToBase7(-10000));
    EXPECT_EQ("-520102", solution.convertToBase7(-88888));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
