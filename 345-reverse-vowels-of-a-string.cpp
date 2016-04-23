//  345. Reverse Vowels of a String
//  
//  Write a function that takes a string as input and reverse only the vowels of a string.
//
//  Example 1:
//  Given s = "hello", return "holle".
//  Example 2:
//  Given s = "leetcode", return "leotcede".
//
//  Tags: Two Pointers, String
//  
//  https://leetcode.com/problems/reverse-vowels-of-a-string/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
private:
    bool isVowel(char c){
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(!isVowel(s[i])){
                i++;
                continue;
            }
            if(!isVowel(s[j])){
                j--;
                continue;
            }

            swap(s[i++], s[j--]);
        }
        return s;
    }
};

TEST(leetcode_345_reverse_vowels_of_a_string, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ("holle", solution->reverseVowels("hello"));
    EXPECT_EQ("leetcode", solution->reverseVowels("leotcede"));
    EXPECT_EQ("xiboazi", solution->reverseVowels("xibaozi"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
