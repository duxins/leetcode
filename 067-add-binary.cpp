//  67. Add Binary
//  
//  Given two binary strings, return their sum (also a binary string).
//
//  For example,
//      a = "11"
//      b = "1"
//      Return "100".
//
//  Tags: Math, String
//  
//  https://leetcode.com/problems/add-binary/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size()) return addBinary(b, a);

        string result = "";
        int x = 0, y = 0;
        int carry = 0;

        for(int i = a.size() - 1; i >=0; i--) {
            int j = i + b.size() - a.size();
            y = (j >=0 && b[j] == '1') ? 1 : 0;
            x = a[i] - '0';
            int sum = x + y + carry;
            carry = sum / 2;
            result = char('0' + sum % 2) + result;
        }

        if(carry) {
            result = '1' + result;
        }

        return result;
    }
};

TEST(leetcode_067_add_binary, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ("100",solution->addBinary("11", "1"));
    EXPECT_EQ("110010",solution->addBinary("110001", "1"));
    EXPECT_EQ("110110",solution->addBinary("110001", "101"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
