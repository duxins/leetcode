//  
//  500. Keyboard Row
//            
//  
//  Given a List of words, return the words that can be typed using letters of alphabet on
//  only one row's of American keyboard like the image below.
//
//  ![keyboard](https://leetcode.com/static/images/problemset/keyboard.png)
//
//  Example 1:
//  Input: ["Hello", "Alaska", "Dad", "Peace"]
//  Output: ["Alaska", "Dad"]
//
//  Note:
//  You may use one character in the keyboard more than once.
//  You may assume the input string will only contain letters of alphabet.
//
//  Tags: Hash Table
//  
//  https://leetcode.com/problems/keyboard-row/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>
#include <locale>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        static unordered_map<char, int> m =  {
                {'q',0}, {'w',0}, {'e', 0}, {'r',0}, {'t',0}, {'y',0}, {'u', 0}, {'i',0}, {'o', 0}, {'p',0},
                {'a',1}, {'s',1}, {'d', 1}, {'f',1}, {'g',1}, {'h',1}, {'j', 1}, {'k',1}, {'l', 1},
                {'z',2}, {'x',2}, {'c', 2}, {'v',2}, {'b',2}, {'n',2}, {'m', 2}
        } ;
        for(string word : words){
            int row = m[tolower(word[0])];
            bool found = true;

            for (int i = 1; i < word.size() ; ++i) {
                if(m[tolower(word[i])] != row){
                    found = false;
                    break;
                }
            }

            if (found) {
                result.push_back(word);
            }
        }
        return result;
    }
};

void EXPECT(vector<string> expected, vector<string> input) {
    Solution solution;
    EXPECT_EQ(expected, solution.findWords(input));
}


TEST(leetcode_500_keyboard_row, Basic)
{
    EXPECT({"Alaska", "Dad"}, {"Hello", "Alaska", "Dad", "Peace"});
    EXPECT({"asdfghjkla","qwertyuiopq","zxcvbnzzm","asdfghjkla","qwertyuiopq","zxcvbnzzm"}, {"asdfghjkla","qwertyuiopq","zxcvbnzzm","asdfghjkla","qwertyuiopq","zxcvbnzzm"});
    EXPECT({"aadsdfghjkla","zxcvbnzzm"}, {"aadsdfghjkla","qwertyuiadfopq","zxadfazm","asadfaedfghjkala","qadfzwertyuiopq","zxcvbnzzm"});
    EXPECT({"ppppppp"}, {"qaz","wsx","edc","rfv","tgb","yhn","ujm","ik","pklo","ppppppp"});
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
