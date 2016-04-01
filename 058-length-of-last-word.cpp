//  58. Length of Last Word
//  
//  Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//  If the last word does not exist, return 0.
//  Note: A word is defined as a character sequence consists of non-space characters only.
//
//  For example, 
//      Given s = "Hello World",
//      return 5.
//
//  Tags: String
//  
//  https://leetcode.com/problems/length-of-last-word/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool isBoundary = true;

        for(auto c : s){
            if(c == ' '){
                isBoundary = true;
            }else{
                length = isBoundary ? 1 : length + 1;
                isBoundary = false;
            }
        }

        return length;
    }
};

TEST(leetcode_058_length_of_last_word, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->lengthOfLastWord("b  a  "));
    EXPECT_EQ(5, solution->lengthOfLastWord("hello  "));
    EXPECT_EQ(2, solution->lengthOfLastWord("xi bao zi"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
