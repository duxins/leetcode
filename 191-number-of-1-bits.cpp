//  191. Number of 1 Bits
//  
//  Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//  For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
//  Credits:Special thanks to @ts for adding this problem and creating all test cases.
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/number-of-1-bits/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 0 ; i < 32; i++){
            if(n & 1) count++;
            n = n >> 1;
        }
        return count;
    }
};

TEST(leetcode_191_number_of_1_bits, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(0, solution->hammingWeight(0));
    EXPECT_EQ(1, solution->hammingWeight(1));
    EXPECT_EQ(2, solution->hammingWeight(3));
    EXPECT_EQ(1, solution->hammingWeight(4));
    EXPECT_EQ(2, solution->hammingWeight(6));
    EXPECT_EQ(3, solution->hammingWeight(11));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
