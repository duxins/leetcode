//  6. ZigZag Conversion
//  
//  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//  (you may want to display this pattern in a fixed font for better legibility)
//
//  P   A   H   N
//  A P L S I I G
//  Y   I   R
//
//  And then read line by line: "PAHNAPLSIIGYIR"
//  Write the code that will take a string and make this conversion given a number of rows:
//  string convert(string text, int nRows);
//  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//
//  Tags: String
//  
//  https://leetcode.com/problems/zigzag-conversion/    

#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string result;

        vector<string> v (numRows);

        for(int i = 0, j = 0, dir = -1; i < s.length(); j += dir, i++){
            v[j] += s[i];
            if(j == 0 || j == numRows - 1){
                dir = -dir;
            }
        }

        for(int i = 0; i < numRows; i++){
            result+= v[i];
        }

        return result;
    }
};


TEST(leetcode_006_zigzag_conversion, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ("ABC", solution->convert("ABC", 1));
    EXPECT_EQ("A", solution->convert("A", 3));
    EXPECT_EQ("tbwlmrtsvt", solution->convert("twrvtlbmst", 4));
    EXPECT_EQ("PYAIHRNAPLSIIG", solution->convert("PAYPALISHIRING", 2));
    EXPECT_EQ("PAHNAPLSIIGYIR", solution->convert("PAYPALISHIRING", 3));
    EXPECT_EQ("xtiqgjsrileielhfkdczh", solution->convert("xtigsieehkchzdflilrjq", 12));
    EXPECT_EQ("Aaidoeswr,haenme,rtesqecouishtabrateaeaietedrcinwtgnrlloacsoajsmnsoucutoadodiiesplnrmiaodprs,ubroohreunefnttacneedhsmwynihrieto,iheeaalwnefrdutettpntainnwrdvdr.",
              solution->convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 2));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
