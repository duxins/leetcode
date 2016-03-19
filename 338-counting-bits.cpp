//  338. Counting Bits
//  
//  Given a non negative integer number num.
//  For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and
//  return them as an array.
//
//  Example:
//      For num = 5 you should return [0,1,1,2,1,2].
//
//  Follow up:
//      It is very easy to come up with a solution with run time O(n*sizeof(integer)).
//      But can you do it in linear time O(n) /possibly in a single pass?
//      Space complexity should be O(n).
//
//      Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.
//
//  Hints:
//      * You should make use of what you have produced already.
//      * Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
//      * Or does the odd/even status of the number help you in calculating the number of 1s?
//
//  Tags: Dynamic Programming, Bit Manipulation
//  
//  https://leetcode.com/problems/counting-bits/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>result(num+1, 0);

        for (int i = 0; i <= num / 2; ++i) {
            result[2 * i] = result[i];
            result[2 * i + 1] = result[i] + 1;
        }

        return result;
    }
};


bool vector_equal(vector<int>&a, vector<int>&b){
    if(a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) return false;
    }
    return true;
}


TEST(leetcode_338_counting_bits, Basic)
{
    Solution *solution = new Solution();
    vector<int> result = solution->countBits(5);
    vector<int> expected{0, 1, 1, 2, 1, 2};
    EXPECT_TRUE(vector_equal(expected, result));

    result = solution->countBits(0);
    expected = {0};
    EXPECT_TRUE(vector_equal(expected, result));

    result = solution->countBits(1);
    expected = {0, 1};
    EXPECT_TRUE(vector_equal(expected, result));

    result = solution->countBits(6);
    expected = {0, 1, 1, 2, 1, 2, 2};
    EXPECT_TRUE(vector_equal(expected, result));

    result = solution->countBits(10);
    expected = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2};
    EXPECT_TRUE(vector_equal(expected, result));

    result = solution->countBits(20);
    expected = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2};
    EXPECT_TRUE(vector_equal(expected, result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
