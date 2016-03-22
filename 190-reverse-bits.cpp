//  190. Reverse Bits
//  
//  Reverse bits of a given 32 bits unsigned integer.
//  For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//  Follow up:
//  If this function is called many times, how would you optimize it?
//  Related problem: Reverse Integer
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/reverse-bits/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0; i<32; i++){
            result |= ((n >> (31-i)) & 1) << i;
        }
        return result;
    }
};

TEST(leetcode_190_reverse_bits, Basic)
{
    Solution *solution = new Solution();

    EXPECT_EQ(2147483648, solution->reverseBits(0b1));
    EXPECT_EQ(1073741824, solution->reverseBits(0b10));
    EXPECT_EQ(3221225472, solution->reverseBits(0b11));
    EXPECT_EQ(3154116608, solution->reverseBits(0b111101));
    EXPECT_EQ(964176192,  solution->reverseBits(0b00000010100101000001111010011100));
    EXPECT_EQ(1,          solution->reverseBits(0b10000000000000000000000000000000));
    EXPECT_EQ(2,          solution->reverseBits(0b1000000000000000000000000000000));
    EXPECT_EQ(4,          solution->reverseBits(0b100000000000000000000000000000));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
