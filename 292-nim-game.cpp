//  292. Nim Game
//  
//  You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you
//  take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first
//  turn to remove the stones.
//
//  Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can
//  win the game given the number of stones in the heap.
//
//  For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you
//  remove, the last stone will always be removed by your friend.
//  If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner? 
//
//  Tags: Brainteaser
//  
//  https://leetcode.com/problems/nim-game/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n  % 4 == 0 ? false : true;
    }
};

TEST(leetcode_292_nim_game, Basic)
{
    Solution *solution = new Solution();
    EXPECT_FALSE(solution->canWinNim(4));
    EXPECT_FALSE(solution->canWinNim(8));
    EXPECT_FALSE(solution->canWinNim(8888));
    EXPECT_FALSE(solution->canWinNim(888888));

    EXPECT_TRUE(solution->canWinNim(1));
    EXPECT_TRUE(solution->canWinNim(2));
    EXPECT_TRUE(solution->canWinNim(3));
    EXPECT_TRUE(solution->canWinNim(5));
    EXPECT_TRUE(solution->canWinNim(1111));
    EXPECT_TRUE(solution->canWinNim(9999));
    EXPECT_TRUE(solution->canWinNim(1199886170));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
