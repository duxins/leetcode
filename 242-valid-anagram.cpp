//  242. Valid Anagram
//  
//  Given two strings s and t, write a function to determine if t is an anagram of s.
//
//  For example,
//  s = "anagram", t = "nagaram", return true.
//  s = "rat", t = "car", return false.
//
//  Note:
//  You may assume the string contains only lowercase alphabets.
//  Follow up:
//  What if the inputs contain unicode characters? How would you adapt your solution to such case?
//
//  Tags: Hash Table, Sort
//  
//  https://leetcode.com/problems/valid-anagram/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int m[26] = {0};

        for(int i = 0; i < s.size(); i++){
            m[s[i] - 'a'] ++;
            m[t[i] - 'a'] --;
        }

        for(int i = 0; i< 26; i++){
            if(m[i] != 0) return false;
        }
        return true;
    }
};

TEST(leetcode_242_valid_anagram, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isAnagram("nagaram", "anagram"));
    EXPECT_FALSE(solution->isAnagram("rat", "cat"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
