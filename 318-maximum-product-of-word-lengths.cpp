//  318. Maximum Product of Word Lengths
//  
//  Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
//  You may assume that each word will contain only lower case letters.
//  If no such two words exist, return 0.
//
//  Example 1:
//  Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//  Return 16
//  The two words can be "abcw", "xtfn".
//
//  Example 2:
//  Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//  Return 4
//  The two words can be "ab", "cd".
//
//  Example 3:
//  Given ["a", "aa", "aaa", "aaaa"]
//  Return 0
//  No such pair of words.
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/maximum-product-of-word-lengths/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        int result = 0;
        int v[size];

        for(int i = 0; i < size; i++){
            v[i] = 0;
            for(char c : words[i]){
                v[i] |= (1 << (c - 'a'));
            }
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if((v[i] & v[j]) == 0){
                    int product = words[i].length() * words[j].length();
                    result = product > result ? product : result;
                }
            }
        }

        return result;
    }
};


TEST(leetcode_318_maximum_product_of_word_lengths, Basic)
{
    Solution *solution = new Solution();
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    EXPECT_EQ(16, solution->maxProduct(words));

    words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    EXPECT_EQ(4, solution->maxProduct(words));

    words = {"a", "aa", "aaa", "aaaa"};
    EXPECT_EQ(0, solution->maxProduct(words));

    words = {};
    EXPECT_EQ(0, solution->maxProduct(words));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
