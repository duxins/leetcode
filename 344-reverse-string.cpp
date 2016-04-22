//  344. Reverse String
//  
//  Write a function that takes a string as input and returns the string reversed.
//  Example:
//  Given s = "hello", return "olleh".
//  https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() -1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

TEST(leetcode_344_reverse_string, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ("olleh", solution->reverseString("hello"));
    EXPECT_EQ("izoabix", solution->reverseString("xibaozi"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
