//  
//  12. Integer to Roman
//            
//  
//  Given an integer, convert it to a roman numeral.
//  Input is guaranteed to be within the range from 1 to 3999.
//
//  Tags: Math, String
//  
//  https://leetcode.com/problems/integer-to-roman/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static vector<vector<string>> v {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"},
        };

        string res;
        res += v[3][(num/1000)%10];
        res += v[2][(num/100)%10];
        res += v[1][(num/10)%10];
        res += v[0][num%10];
        return res;
    }
};


TEST(leetcode_012_integer_to_roman, Basic)
{
    Solution solution;
    EXPECT_EQ("II",        solution.intToRoman(2));
    EXPECT_EQ("X",         solution.intToRoman(10));
    EXPECT_EQ("XIX",       solution.intToRoman(19));
    EXPECT_EQ("C",         solution.intToRoman(100));
    EXPECT_EQ("XCIX",      solution.intToRoman(99));
    EXPECT_EQ("DCLXXVIII", solution.intToRoman(678));
    EXPECT_EQ("M",         solution.intToRoman(1000));
    EXPECT_EQ("MM",        solution.intToRoman(2000));
    EXPECT_EQ("MMM",       solution.intToRoman(3000));
    EXPECT_EQ("MCCXXXIV",  solution.intToRoman(1234));
    EXPECT_EQ("MMCCXXII",  solution.intToRoman(2222));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
