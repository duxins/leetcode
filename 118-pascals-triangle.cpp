//  118. Pascal's Triangle
//  
//  Given numRows, generate the first numRows of Pascal's triangle.
//  For example, given numRows = 5,
//
//  Return
//  [
//        [1],
//       [1,1],
//      [1,2,1],
//     [1,3,3,1],
//    [1,4,6,4,1]
//  ]
//
//  Tags: Array
//  
//  https://leetcode.com/problems/pascals-triangle/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i = 0; i< numRows; i++){
            vector<int> row;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    row.push_back(1);
                }else{
                    row.push_back(result[i-1][j-1] + result[i-1][j]);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};

TEST(leetcode_118_pascals_triangle, Basic)
{
    Solution *solution = new Solution();
    vector<vector<int>> expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    EXPECT_EQ(expected, solution->generate(5));

    expected = {};
    EXPECT_EQ(expected, solution->generate(0));

    expected = {{1}};
    EXPECT_EQ(expected, solution->generate(1));

    expected = {{1}, {1, 1}};
    EXPECT_EQ(expected, solution->generate(2));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
