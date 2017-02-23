//  
//  520. Detect Capital
//            
//  
//  Given a word, you need to judge whether the usage of capitals in it is right or not.
//  We define the usage of capitals in a word to be right when one of the following cases holds:
//
//  All letters in this word are capitals, like "USA".
//  All letters in this word are not capitals, like "leetcode".
//  Only the first letter in this word is capital if it has more than one letter, like "Google".
//
//  Otherwise, we define that this word doesn't use capitals in a right way.
//
//  Example 1:
//  Input: "USA"
//  Output: True
//
//  Example 2:
//  Input: "FlaG"
//  Output: False
//
//  Note:
//  The input will be a non-empty word consisting of uppercase and lowercase latin letters.
//
//  Tags: String
//  
//  https://leetcode.com/problems/detect-capital/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals = 0;
        for (char c : word) {
            if(c >= 'A' && c <= 'Z'){
                capitals ++;
            }
        }
        return (capitals == 0 || capitals == word.size() || (capitals == 1 && word[0] >= 'A' && word[0] <= 'Z'));
    }
};

TEST(leetcode_520_detect_capital, Basic)
{
    Solution solution;
    EXPECT_TRUE(solution.detectCapitalUse("Z"));
    EXPECT_TRUE(solution.detectCapitalUse("z"));
    EXPECT_TRUE(solution.detectCapitalUse("USA"));
    EXPECT_TRUE(solution.detectCapitalUse("Google"));
    EXPECT_TRUE(solution.detectCapitalUse("leetcode"));
    EXPECT_FALSE(solution.detectCapitalUse("FlaG"));
    EXPECT_FALSE(solution.detectCapitalUse("ZZZZZZZZZZZZz"));
    EXPECT_FALSE(solution.detectCapitalUse("aAAAAAAAAAAAA"));
    EXPECT_FALSE(solution.detectCapitalUse("fFFFFFFFFFFFF"));
    EXPECT_FALSE(solution.detectCapitalUse("aAaaaaaaaaaaaZ"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
