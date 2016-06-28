//  290. Word Pattern
//  
//  Given a pattern and a string str, find if str follows the same pattern.
//  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//  Examples:
//  pattern = "abba", str = "dog cat cat dog" should return true.
//  pattern = "abba", str = "dog cat cat fish" should return false.
//  pattern = "aaaa", str = "dog cat cat dog" should return false.
//  pattern = "abba", str = "dog dog dog dog" should return false.
//
//  Notes:
//  You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//
//  Tags: Hash Table
//  
//  https://leetcode.com/problems/word-pattern/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> words;

        //Taken from http://stackoverflow.com/a/236803
        stringstream ss(str);
        string item;
        while(getline(ss, item, ' ')){
            words.push_back(item);
        }

        if(words.size() != pattern.size()){
            return false;
        }

        for(int i= 0; i<words.size(); i++){
            char c = pattern[i];
            string word = words[i];

            if(m1.find(c) == m1.end()){
                if(m2.find(word) != m2.end()){
                    return false;
                }
                m2[word] = c;
                m1[c] = word;
            }else if(m1[c] != word){
                return false;
            }
        }

        return true;
    }
};

TEST(leetcode_290_word_pattern, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->wordPattern("abba", "dog cat cat dog"));
    EXPECT_TRUE(solution->wordPattern("deadbeefa", "d e a d b e e f"));
    EXPECT_TRUE(solution->wordPattern("abcdefghijklmnnmlkjihgfedcba", "aa bb cc dd ee ff gg hh ii jj kk ll mm nn nn mm ll kk jj ii hh gg ff ee dd cc bb aa"));
    EXPECT_TRUE(solution->wordPattern("itwasthebestoftimesitwastheworstoftimesitwastheageofwisdomitwastheageoffoolishnessitwastheepochofbeliefitwastheepochofincredulityitwastheseasonoflightitwastheseasonofdarknessitwasthespringofhopeitwasthewinterofdespair",
                                      "i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee bbbbbbbbbbbbbbbbbb eeeeeeeeeee sssss tttttttttttttttt oo fffffffff tttttttttttttttt i mmm eeeeeeeeeee sssss i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee wwww oo rrrrrrrrrrrrrr sssss tttttttttttttttt oo fffffffff tttttttttttttttt i mmm eeeeeeeeeee sssss i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee aa gggggggggggggg eeeeeeeeeee oo fffffffff wwww i sssss ddddddddddd oo mmm i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee aa gggggggggggggg eeeeeeeeeee oo fffffffff fffffffff oo oo llllllll i sssss hhhhhhhhhhhhhhhhhhhhhhh nnnnnn eeeeeeeeeee sssss sssss i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee eeeeeeeeeee pppp oo cccccccccccc hhhhhhhhhhhhhhhhhhhhhhh oo fffffffff bbbbbbbbbbbbbbbbbb eeeeeeeeeee llllllll i eeeeeeeeeee fffffffff i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee eeeeeeeeeee pppp oo cccccccccccc hhhhhhhhhhhhhhhhhhhhhhh oo fffffffff i nnnnnn cccccccccccc rrrrrrrrrrrrrr eeeeeeeeeee ddddddddddd uuuuuuuuuu llllllll i tttttttttttttttt yyyyyyyyyyy i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee sssss eeeeeeeeeee aa sssss oo nnnnnn oo fffffffff llllllll i gggggggggggggg hhhhhhhhhhhhhhhhhhhhhhh tttttttttttttttt i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee sssss eeeeeeeeeee aa sssss oo nnnnnn oo fffffffff ddddddddddd aa rrrrrrrrrrrrrr kkkkkkkkk nnnnnn eeeeeeeeeee sssss sssss i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee sssss pppp rrrrrrrrrrrrrr i nnnnnn gggggggggggggg oo fffffffff hhhhhhhhhhhhhhhhhhhhhhh oo pppp eeeeeeeeeee i tttttttttttttttt wwww aa sssss tttttttttttttttt hhhhhhhhhhhhhhhhhhhhhhh eeeeeeeeeee wwww i nnnnnn tttttttttttttttt eeeeeeeeeee rrrrrrrrrrrrrr oo fffffffff ddddddddddd eeeeeeeeeee sssss pppp aa i rrrrrrrrrrrrrr"));
    EXPECT_FALSE(solution->wordPattern("abba", "dog cat cat fish"));
    EXPECT_FALSE(solution->wordPattern("aaaa", "dog cat cat dog"));
    EXPECT_FALSE(solution->wordPattern("abba", "dog dog dog dog"));
    EXPECT_FALSE(solution->wordPattern("abaaba", "dog cat fish fish cat dog"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
