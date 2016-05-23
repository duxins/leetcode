//  9. Palindrome Number
//  
//  Determine whether an integer is a palindrome. Do this without extra space.
//  click to show spoilers.
//
//  Some hints:
//  Could negative integers be palindromes? (ie, -1)
//  If you are thinking of converting the integer to string, note the restriction of using extra space.
//  You could also try reversing an integer. However, if you have solved the problem
//  "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//  There is a more generic way of solving this problem.
//
//  Tags: Math
//  
//  https://leetcode.com/problems/palindrome-number/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int r = 0;
        int t = x;

        while(t > 0){
            r = 10 * r + t % 10;
            t /= 10;
        }

        return x == r;
    }
};


TEST(leetcode_009_palindrome_number, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isPalindrome(1));
    EXPECT_TRUE(solution->isPalindrome(101));
    EXPECT_TRUE(solution->isPalindrome(1001));
    EXPECT_TRUE(solution->isPalindrome(10001));
    EXPECT_TRUE(solution->isPalindrome(88888));
    EXPECT_TRUE(solution->isPalindrome(2222222));
    EXPECT_TRUE(solution->isPalindrome(2222222));
    EXPECT_TRUE(solution->isPalindrome(2147447412));

    EXPECT_FALSE(solution->isPalindrome(10002));
    EXPECT_FALSE(solution->isPalindrome(1000021));
    EXPECT_FALSE(solution->isPalindrome(1000021));
    EXPECT_FALSE(solution->isPalindrome(-2147483648));
    EXPECT_FALSE(solution->isPalindrome(-2147447412));
    EXPECT_FALSE(solution->isPalindrome(INT_MAX));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
