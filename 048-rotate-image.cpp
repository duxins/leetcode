//  48. Rotate Image
//  
//  You are given an n x n 2D matrix representing an image.
//  Rotate the image by 90 degrees (clockwise).
//  Follow up:
//  Could you do this in-place?
//  Subscribe to see which companies asked this question
//  
//  Tags: Array
//  
//  https://leetcode.com/problems/rotate-image/    

#include <iostream>
#include <gtest/gtest.h>
#include <utility>

using namespace std;

class Solution {

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
    }
};

void judge(vector<vector<int>> input, vector<vector<int>> expected){
    Solution solution = Solution();
    solution.rotate(input);
    EXPECT_EQ(expected, input);
}

TEST(leetcode_048_rotate_image, Basic)
{
    judge({{1,2},{3,4}}, {{3,1},{4,2}});
    judge({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}, {{13,9,5,1},{14,10,6,2},{15,11,7,3},{16,12,8,4}});
    judge({{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}},
          {{4,33,13,32,12,2},{24,1,14,33,27,29},{1,20,32,32,9,20},{6,7,27,2,25,26},{32,21,22,28,13,16},{34,7,26,14,21,28}} );
    judge({{43,39,3,33,37,20,14},{9,18,9,-1,40,22,38},{14,42,3,23,12,14,32},{18,31,45,11,8,-1,31},{28,44,14,23,40,24,13},{29,45,33,45,20,0,45},{12,23,35,32,22,39,8}},
          {{12,29,28,18,14,9,43},{23,45,44,31,42,18,39},{35,33,14,45,3,9,3},{32,45,23,11,23,-1,33},{22,20,40,8,12,40,37},{39,0,24,-1,14,22,20},{8,45,13,31,32,38,14}});
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
