//  374. Guess Number Higher or Lower
//  
//  We are playing the Guess Game. The game is as follows: 
//  I pick a number from 1 to n. You have to guess which number I picked.
//  Every time you guess wrong, I'll tell you whether the number is higher or lower.
//  You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//  -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
//  Example:
//  n = 10, I pick 6.
//  Return 6.
//
//  Tags: Binary Search
//  
//  https://leetcode.com/problems/guess-number-higher-or-lower/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        while(i <= j){
            int mid = i + (j - i) / 2;
            int g = guess(mid);
            if(g == 0){
                return mid;
            }else if(g == 1){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return 0;
    }
};

int gPick;

int guess(int num){
    if(num == gPick) return 0;
    return num > gPick ? -1 : 1;
}

void judge(int n, int pick, int expected){
    gPick = pick;
    Solution solution;
    EXPECT_EQ(expected, solution.guessNumber(n));
}

TEST(leetcode_374_guess_number_higher_or_lower, Basic)
{
    judge(1, 1, 1);
    judge(5, 3, 3);
    judge(10, 5, 5);
    judge(100, 88, 88);
    judge(8888, 111, 111);
    judge(10000, 555, 555);
    judge(INT_MAX, 10, 10);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
