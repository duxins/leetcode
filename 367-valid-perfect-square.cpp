//  367. Valid Perfect Square
//  
//  Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
//  Note: Do not use any built-in library function such as sqrt.
//
//  Example 1:
//  Input: 16
//  Returns: True
//
//  Example 2:
//  Input: 14
//  Returns: False
//
//  Tags: Binary Search
//  
//  https://leetcode.com/problems/valid-perfect-square/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;

        int i = 2, j = num;
        while(i <= j){
            long long m = i + (j - i) /2;
            if(m * m > num) {
                j = m - 1;
            }else if(m * m < num){
                i = m + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

void judge(int input, bool expected){
    Solution solution;
    EXPECT_EQ(expected, solution.isPerfectSquare(input)) << "input: " << input << ", expected: " << expected;
}

TEST(leetcode_367_valid_perfect_square, Basic)
{
    unordered_map<int, bool> testcases = {
            {1, true},
            {4, true},
            {9, true},
            {16, true},
            {25, true},
            {36, true},
            {49, true},
            {64, true},
            {81, true},
            {100, true},
            {64516, true},

            {93025, true},
            {100489, true},
            {104976, true},
            {223729, true},
            {361201, true},
            {602176, true},
            {808201, true},

            {2, false},
            {3, false},
            {5, false},
            {7, false},
            {11, false},
            {15, false},
            {107, false},
            {598, false},
            {681, false},
            {775, false},
            {93023, false},
            {93024, false},
            {2147483647, false},
    };

    for(auto&kv : testcases){
        judge(kv.first, kv.second);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
