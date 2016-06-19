//  201. Bitwise AND of Numbers Range
//  
//  Given a range [m, n] where 0 
//  For example, given the range [5, 7], you should return 4.
//
//  Tags: Bit Manipulation
//  
//  https://leetcode.com/problems/bitwise-and-of-numbers-range/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m!=n){
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m << i;
    }
};

TEST(leetcode_201_bitwise_and_of_numbers_range, Basic)
{
    Solution * solution = new Solution();
    EXPECT_EQ(4, solution->rangeBitwiseAnd(5, 7));
    EXPECT_EQ(0, solution->rangeBitwiseAnd(0, 5));
    EXPECT_EQ(0, solution->rangeBitwiseAnd(0, 2));
    EXPECT_EQ(0, solution->rangeBitwiseAnd(0, 0));
    EXPECT_EQ(1, solution->rangeBitwiseAnd(1, 1));
    EXPECT_EQ(11, solution->rangeBitwiseAnd(11, 11));
    EXPECT_EQ(0, solution->rangeBitwiseAnd(21, 32));
    EXPECT_EQ(22, solution->rangeBitwiseAnd(22, 23));
    EXPECT_EQ(8, solution->rangeBitwiseAnd(8, 11));
    EXPECT_EQ(8, solution->rangeBitwiseAnd(9, 11));
    EXPECT_EQ(64, solution->rangeBitwiseAnd(64, 101));
    EXPECT_EQ(64, solution->rangeBitwiseAnd(65, 101));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
