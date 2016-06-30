//  371. Sum of Two Integers
//  
//  Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//  Example:
//  Given a = 1 and b = 2, return 3.
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/sum-of-two-integers/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0){
            return a;
        }else{
            return getSum( a ^ b, (a & b) << 1);
        }
    }
};

void judge(int a, int b){
    Solution solution;
    EXPECT_EQ(a + b, solution.getSum(a, b));
}

TEST(leetcode_371_sum_of_two_integers, Basic)
{
    judge(1, 2);
    judge(2, 3);
    judge(4, 5);
    judge(5, 6);
    judge(9, 9);
    judge(100, 110);
    judge(1234, 4321);
    judge(1234, -4321);
    judge(1234, -1);
    judge(111111, 999999);
    judge(INT_MAX, -1);
    judge(0, INT_MAX);
    judge(-1, INT_MAX);
    judge(-100, INT_MAX);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
