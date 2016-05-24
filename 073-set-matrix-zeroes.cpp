//  73. Set Matrix Zeroes
//  
//  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//  click to show follow up.
//  Follow up:
//  Did you use extra space?
//  A straight forward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still not the best solution.
//  Could you devise a constant space solution?
//
//  Tags: Array
//  
//  https://leetcode.com/problems/set-matrix-zeroes/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false;
        bool firstCol = false;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i == 0) firstRow = true;
                    if(j == 0) firstCol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }


        if(firstCol){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }

        if(firstRow){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
    }
};

TEST(leetcode_073_set_matrix_zeroes, Basic)
{
    Solution *solution = new Solution();
    vector<vector<int>> matrix      = {{1},{2},{0}};
    vector<vector<int>> expected    = {{0},{0},{0}};
    solution->setZeroes(matrix);
    EXPECT_EQ(expected, matrix);

    matrix      = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    expected    = {{0,0,0,0},{0,0,0,4},{0,0,0,0},{0,0,0,3},{0,0,0,0}};
    solution->setZeroes(matrix);
    EXPECT_EQ(expected, matrix);

    matrix      = {{7,1,0},{9,4,2},{4,6,4},{2,2,8},{5,3,2},{1,3,2},{3,1,8},{7,4,9},{4,9,7},{9,5,8}};
    expected    = {{0,0,0},{9,4,0},{4,6,0},{2,2,0},{5,3,0},{1,3,0},{3,1,0},{7,4,0},{4,9,0},{9,5,0}};
    solution->setZeroes(matrix);
    EXPECT_EQ(expected, matrix);

    matrix      = {{8,5,3,5,8,1,3,4,3,4,7,4},
                   {9,4,0,7,5,9,2,8,4,4,4,4},
                   {1,2,7,7,4,5,4,2,2,7,9,2},
                   {0,2,6,4,6,5,0,5,9,2,4,7},
                   {2,9,5,6,3,0,2,4,2,1,1,7},
                   {8,6,1,0,5,1,3,6,5,1,2,4},
                   {7,4,1,8,7,6,5,1,5,3,9,8},
                   {3,4,4,5,5,5,4,6,3,8,6,1},
                   {1,1,7,6,3,1,0,0,7,4,8,6},
                   {0,6,7,7,9,7,7,4,3,1,1,0},
                   {8,6,6,2,6,3,5,7,4,4,5,9}};
    expected    = {{0,5,0,0,8,0,0,0,3,4,7,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,2,0,0,4,0,0,0,2,7,9,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,4,0,0,7,0,0,0,5,3,9,0},
                   {0,4,0,0,5,0,0,0,3,8,6,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0,0,0},
                   {0,6,0,0,6,0,0,0,4,4,5,0}};
    solution->setZeroes(matrix);
    EXPECT_EQ(expected, matrix);

    matrix      = {{3,5,5,6,9,1,4,5,0,5},
                   {2,7,9,5,9,5,4,9,6,8},
                   {6,0,7,8,1,0,1,6,8,1},
                   {7,2,6,5,8,5,6,5,0,6},
                   {2,3,3,1,0,4,6,5,3,5},
                   {5,9,7,3,8,8,5,1,4,3},
                   {2,4,7,9,9,8,4,7,3,7},
                   {3,5,2,8,8,2,2,4,9,8}};
    expected    = {{0,0,0,0,0,0,0,0,0,0},
                   {2,0,9,5,0,0,4,9,0,8},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0,0,0},
                   {5,0,7,3,0,0,5,1,0,3},
                   {2,0,7,9,0,0,4,7,0,7},
                   {3,0,2,8,0,0,2,4,0,8}};
    solution->setZeroes(matrix);
    EXPECT_EQ(expected, matrix);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
