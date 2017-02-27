//  
//              476. Number Complement
//            
//  
//  Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
//  Note:
//  The given integer is guaranteed to fit within the range of a 32-bit signed integer.
//  You could assume no leading zero bit in the integer’s binary representation.
//
//  Example 1:
//  Input: 5
//  Output: 2
//  Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
//
//  Example 2:
//  Input: 1
//  Output: 0
//  Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
//
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/number-complement/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while(mask & num){
            mask <<= 1;
        }
        return mask ^ ~num;
    }
};

TEST(leetcode_476_number_complement, Basic)
{
    Solution solution;
    EXPECT_EQ(2,    solution.findComplement(5));
    EXPECT_EQ(0,    solution.findComplement(0));
    EXPECT_EQ(0,    solution.findComplement(1));
    EXPECT_EQ(27,   solution.findComplement(100));
    EXPECT_EQ(147,  solution.findComplement(876));
    EXPECT_EQ(813,  solution.findComplement(1234));
    EXPECT_EQ(7495, solution.findComplement(8888));
    EXPECT_EQ(2,    solution.findComplement(INT_MAX -2));
    EXPECT_EQ(1,    solution.findComplement(INT_MAX -1));
    EXPECT_EQ(0,    solution.findComplement(INT_MAX));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
