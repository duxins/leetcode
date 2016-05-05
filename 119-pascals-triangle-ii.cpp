//  119. Pascal's Triangle II
//  
//  Given an index k, return the kth row of the Pascal's triangle.
//  For example, given k = 3,
//  Return [1,3,3,1].
//
//  Note:
//  Could you optimize your algorithm to use only O(k) extra space?
//
//  Tags: Array
//  
//  https://leetcode.com/problems/pascals-triangle-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for(int i = 0; i<= rowIndex; i++){
            for(int j = i-1; j>0; j--){
                result[j] = result[j] + result[j-1];
            }
        }
        return result;
    }
};

TEST(leetcode_119_pascals_triangle_ii, Basic)
{
    Solution *solution = new Solution();
    vector<int> expected = {1, 3, 3, 1};
    EXPECT_EQ(expected, solution->getRow(3));

    expected = {1};
    EXPECT_EQ(expected, solution->getRow(0));

    expected = {1, 1};
    EXPECT_EQ(expected, solution->getRow(1));

    expected = {1, 2, 1};
    EXPECT_EQ(expected, solution->getRow(2));

    expected = {1, 4, 6, 4, 1};
    EXPECT_EQ(expected, solution->getRow(4));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
