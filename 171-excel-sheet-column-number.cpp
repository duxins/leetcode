//  171. Excel Sheet Column Number
//  
//  Related to question Excel Sheet Column Title
//  Given a column title as appear in an Excel sheet, return its corresponding column number.
//  For example:
//  A -> 1
//  B -> 2
//  C -> 3
//  ...
//  Z -> 26
//  AA -> 27
//  AB -> 28 
//  Credits:Special thanks to @ts for adding this problem and creating all test cases.
//  Subscribe to see which companies asked this question
//  
//  Tags: Math
//  
//  https://leetcode.com/problems/excel-sheet-column-number/    

#include <iostream>
#include <gtest/gtest.h>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += ( s[i] - 'A' + 1 ) * pow( 26, len-i-1 );
        }
        return sum;
    }
};

TEST(leetcode_171_excel_sheet_column_number, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->titleToNumber("A"));
    EXPECT_EQ(2, solution->titleToNumber("B"));
    EXPECT_EQ(3, solution->titleToNumber("C"));
    EXPECT_EQ(27, solution->titleToNumber("AA"));
    EXPECT_EQ(29, solution->titleToNumber("AC"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
