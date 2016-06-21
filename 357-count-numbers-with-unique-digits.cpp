//  357. Count Numbers with Unique Digits
//  
//  Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
//
//  Example:
//  Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
//
//  Hint:
//
//  1. A direct way is to use the backtracking approach.
//  2. Backtracking should contains three states which are (the current number, number of steps to get that number and a
//     bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0)
//     and count all valid number till we reach number of steps equals to 10n.
//  3. This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
//  4. Let f(k) = count of numbers with unique digits with length equals k.
//  5. f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].
//
//  Tags: Dynamic Programming, Backtracking, Math
//  
//  https://leetcode.com/problems/count-numbers-with-unique-digits/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;

        vector<int> dp (n + 1);
        dp[1] = 10;
        dp[2] = 9 * 9;

        for(int i = 2; i <= n; i++){
            int count = 9;
            for(int j = 0; j <= i - 2; j++){
                count *= (9 - j);
            }
            dp[i] = count + dp[i-1];
        }

        return dp[n];
    }
};

TEST(leetcode_357_count_numbers_with_unique_digits, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1, solution->countNumbersWithUniqueDigits(0));
    EXPECT_EQ(10, solution->countNumbersWithUniqueDigits(1));
    EXPECT_EQ(91, solution->countNumbersWithUniqueDigits(2));
    EXPECT_EQ(739, solution->countNumbersWithUniqueDigits(3));
    EXPECT_EQ(5275, solution->countNumbersWithUniqueDigits(4));
    EXPECT_EQ(32491, solution->countNumbersWithUniqueDigits(5));
    EXPECT_EQ(168571, solution->countNumbersWithUniqueDigits(6));
    EXPECT_EQ(712891, solution->countNumbersWithUniqueDigits(7));
    EXPECT_EQ(2345851, solution->countNumbersWithUniqueDigits(8));
    EXPECT_EQ(5611771, solution->countNumbersWithUniqueDigits(9));
    EXPECT_EQ(8877691, solution->countNumbersWithUniqueDigits(10));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
