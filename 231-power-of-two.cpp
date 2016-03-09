//  231. Power of Two
//  
//  Given an integer, write a function to determine if it is a power of two.
//  Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
//  Subscribe to see which companies asked this question
//  
//  Tags: Math, Bit Manipulation
//  
//  https://leetcode.com/problems/power-of-two/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;

        while(n%2 == 0){
            n=n/2;
        }

        return n==1;
    }
};

TEST(leetcode_231_power_of_two, Basic)
{
    Solution *solution = new Solution();

    int nums[] = {1, 2, 4, 8, 64, 128, 256, 512};

    for (int i = 0; i < (sizeof(nums)/sizeof(int)); ++i) {
        int num = nums[i];
        EXPECT_TRUE(solution->isPowerOfTwo(num)) << num;
    }
}

TEST(leetcode_231_power_of_two, Basic2)
{
    Solution *solution = new Solution();

    int nums[] = {0, 3, 7, 21, 999};

    for (int i = 0; i < (sizeof(nums)/sizeof(int)); ++i) {
        int num = nums[i];
        EXPECT_FALSE(solution->isPowerOfTwo(num)) << num;
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
