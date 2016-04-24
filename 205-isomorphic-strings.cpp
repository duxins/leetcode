//  205. Isomorphic Strings
//  
//  Given two strings s and t, determine if they are isomorphic.
//  Two strings are isomorphic if the characters in s can be replaced to get t.
//  All occurrences of a character must be replaced with another character while preserving the order of characters.
//  No two characters may map to the same character but a character may map to itself.
//
//  For example,
//  Given "egg", "add", return true.
//  Given "foo", "bar", return false.
//  Given "paper", "title", return true.
//  Note:
//  You may assume both s and t have the same length.
//
//  Tags: Hash Table
//  
//  https://leetcode.com/problems/isomorphic-strings/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a[255] = {0};
        int b[255] = {0};

        for(int i = 0; i < s.length(); i++){
            if(a[s[i]] == 0) {
                a[s[i]] = i + 1;
            }

            if(b[t[i]] == 0) {
                b[t[i]] = i + 1;
            }

            if(a[s[i]] != b[t[i]]) return false;
        }
        return true;
    }
};

TEST(leetcode_205_isomorphic_strings, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isIsomorphic("ab", "ab"));
    EXPECT_TRUE(solution->isIsomorphic("egg", "add"));
    EXPECT_TRUE(solution->isIsomorphic("papero", "title"));
    EXPECT_FALSE(solution->isIsomorphic("ab", "aa"));
    EXPECT_FALSE(solution->isIsomorphic("foo", "bar"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
