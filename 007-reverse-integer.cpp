//  7. Reverse Integer
//  
//  Reverse digits of an integer.
//
//  Example1: x =  123, return  321
//  Example2: x = -123, return -321
//
//  Have you thought about this?
//  Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//  If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//  Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//  For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//  Update (2014-11-10):
//  Test cases had been added to test the overflow behavior.
//  Subscribe to see which companies asked this question
//  
//  Tags: Math
//  
//  https://leetcode.com/problems/reverse-integer/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        long result = 0;

        while(n){
            result = result * 10 + n % 10;
            n /= 10;
        }

        result = x > 0 ? result : -result;

        if(result > INT_MAX || result < INT_MIN){
            return 0;
        }

        return result;
    }
};

TEST(leetcode_007_reverse_integer, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(123, solution->reverse(321));
    EXPECT_EQ(-123, solution->reverse(-321));
    EXPECT_EQ(2147483641, solution->reverse(1463847412));
    EXPECT_EQ(0, solution->reverse(2463847412));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
