//  8. String to Integer (atoi)
//  
//  Implement atoi to convert a string to an integer.
//  Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//  Notes: 
//  It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//  Update (2015-02-10):
//  The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
//  spoilers alert... click to show requirements for atoi.
//  Requirements for atoi:
//  The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//  The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//  If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//  If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
//
//  Tags: Math, String
//  
//  https://leetcode.com/problems/string-to-integer-atoi/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool negative = false;
        long result = 0;
        int i = 0;
        for(i = 0; i < str.size() && isspace(str[i]); i++);

        if(str[i] == '-') {
            negative = true;
            i++;
        }else if(str[i] == '+'){
            i++;
        }

        for(; i < str.size() && isdigit(str[i]) ; i++){
            result = result * 10 + (str[i] - '0');
            if(result > INT_MAX) break;
        }

        if(negative) result = - result;

        if(result > INT_MAX) result = INT_MAX;
        if(result < INT_MIN) result = INT_MIN;

        return result;
    }
};


TEST(leetcode_008_string_to_integer_atoi, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(100, solution->myAtoi("  100"));
    EXPECT_EQ(100, solution->myAtoi("         100 00"));
    EXPECT_EQ(-100, solution->myAtoi("  -100"));
    EXPECT_EQ(-100, solution->myAtoi("  -100abc"));
    EXPECT_EQ(100, solution->myAtoi("  +100abc"));
    EXPECT_EQ(100, solution->myAtoi("  100.1"));
    EXPECT_EQ(1, solution->myAtoi("1,000"));
    EXPECT_EQ(INT_MAX, solution->myAtoi("  999999999999999999999"));
    EXPECT_EQ(INT_MIN, solution->myAtoi("-999999999999999999999"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
