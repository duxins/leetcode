//  36. Valid Sudoku
//  
//  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//  The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//  ![A partially filled sudoku which is valid.](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
//
//  A partially filled sudoku which is valid.
//
//  Note:
//  A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
//
//  Tags: Hash Table
//  
//  https://leetcode.com/problems/valid-sudoku/    

#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<string>& board) {

        int row[9][10]      = {0};
        int col[9][10]      = {0};
        int block[3][3][10] = {0};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.') continue;

                int n = board[i][j] - '0';

                if(row[i][n] || col[j][n] || block[i/3][j/3][n]){
                    return false;
                }else{
                    row[i][n] ++;
                    col[j][n] ++;
                    block[i/3][j/3][n] ++;
                }
            }
        }

        return true;
    }

};


TEST(leetcode_036_valid_sudoku, Basic)
{
    Solution *solution = new Solution();
    vector<string> board = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    EXPECT_TRUE(solution->isValidSudoku(board));
    board = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    EXPECT_TRUE(solution->isValidSudoku(board));
    board = {".........",".........",".........",".........",".........",".........",".........",".........","........."};
    EXPECT_TRUE(solution->isValidSudoku(board));
    board = {".1.......",".........",".........",".........",".........",".........",".........",".........",".1......."};
    EXPECT_FALSE(solution->isValidSudoku(board));
    board = {"1........",".........",".1.......",".........",".........",".........",".........",".........","........."};
    EXPECT_FALSE(solution->isValidSudoku(board));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
