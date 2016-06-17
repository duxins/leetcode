//  59. Spiral Matrix II
//  
//  Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//  For example,
//  Given n = 3,
//  You should return the following matrix:
//  [
//      [ 1, 2, 3 ],
//      [ 8, 9, 4 ],
//      [ 7, 6, 5 ]
//  ]
//
//  Tags: Array
//  
//  https://leetcode.com/problems/spiral-matrix-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n, 0));
        int low=0, high = n;
        int num = 1;
        while(low < high){
            for(int i = low; i < high; i++){
                result[low][i] = num++;
            }

            for(int i = low + 1; i < high; i++){
                result[i][high-1] = num++;
            }

            for(int i = high - 2; i >= low; i--){
                result[high-1][i] = num++;
            }

            for(int i = high - 2; i> low; i--){
                result[i][low] = num++;
            }

            high--;
            low++;
        }

        return result;
    }
};

TEST(leetcode_059_spiral_matrix_ii, Basic)
{
    Solution *solution = new Solution();
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(expected, solution->generateMatrix(1));
    expected = {{1,2,3},{8,9,4},{7,6,5}};
    EXPECT_EQ(expected, solution->generateMatrix(3));
    expected = {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    EXPECT_EQ(expected, solution->generateMatrix(4));
    expected = {{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}};
    EXPECT_EQ(expected, solution->generateMatrix(5));
    expected = {{1,2,3,4,5,6,7,8,9,10,11},
                {40,41,42,43,44,45,46,47,48,49,12},
                {39,72,73,74,75,76,77,78,79,50,13},
                {38,71,96,97,98,99,100,101,80,51,14},
                {37,70,95,112,113,114,115,102,81,52,15},
                {36,69,94,111,120,121,116,103,82,53,16},
                {35,68,93,110,119,118,117,104,83,54,17},
                {34,67,92,109,108,107,106,105,84,55,18},
                {33,66,91,90,89,88,87,86,85,56,19},
                {32,65,64,63,62,61,60,59,58,57,20},
                {31,30,29,28,27,26,25,24,23,22,21}};
    EXPECT_EQ(expected, solution->generateMatrix(11));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
