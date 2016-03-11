//  168. Excel Sheet Column Title
//  
//  Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//  For example:
//  1 -> A
//  2 -> B
//  3 -> C
//  ...
//  26 -> Z
//  27 -> AA
//  28 -> AB 
//  Credits:Special thanks to @ifanchu for adding this problem and creating all test cases.
//  Subscribe to see which companies asked this question
//  
//  Tags: Math
//  
//  https://leetcode.com/problems/excel-sheet-column-title/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n){
            result = (char)('A' + (--n)%26) + result;
            n /= 26;
        }
        return result;
    }
};

TEST(leetcode_168_excel_sheet_column_title, Basic)
{
    Solution *sol = new Solution();
    EXPECT_EQ("A", sol->convertToTitle(1));
    EXPECT_EQ("B", sol->convertToTitle(2));
    EXPECT_EQ("Z", sol->convertToTitle(26));
    EXPECT_EQ("AA", sol->convertToTitle(27));
    EXPECT_EQ("AB", sol->convertToTitle(28));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
