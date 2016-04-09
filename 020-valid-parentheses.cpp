//  20. Valid Parentheses
//  
//  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
//  Tags: Stack, String
//  
//  https://leetcode.com/problems/valid-parentheses/    

#include <iostream>
#include <gtest/gtest.h>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto c: s){
            if(st.empty()){
                st.push(c);
            }else if( (c == ')' && st.top() == '(') || (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[')){
                st.pop();
            }else{
                st.push(c);
            }
        }

        return st.empty();
    }
};

TEST(leetcode_020_valid_parentheses, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isValid("()"));
    EXPECT_TRUE(solution->isValid("()[]{}"));
    EXPECT_FALSE(solution->isValid("(]"));
    EXPECT_FALSE(solution->isValid("([)]"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
