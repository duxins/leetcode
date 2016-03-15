//  69. Sqrt(x)
//  
//  Implement int sqrt(int x).
//  Compute and return the square root of x.
//  Subscribe to see which companies asked this question
//  
//  Tags: Math, Binary Search
//  
//  https://leetcode.com/problems/sqrtx/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;

        int i = 1, j = x;
        while(i < j - 1){
            long long  mid = (j - i) / 2 + i;
            if(mid * mid == x) return mid;
            if(mid * mid < x){
                i = mid;
            }else{
                j = mid;
            }
        }
        return i;
    }
};


TEST(leetcode_069_sqrtx, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(0, solution->mySqrt(0));
    EXPECT_EQ(1, solution->mySqrt(3));
    EXPECT_EQ(4, solution->mySqrt(16));
    EXPECT_EQ(94, solution->mySqrt(8888));
    EXPECT_EQ(46340, solution->mySqrt(2147483647));
    EXPECT_EQ(46339, solution->mySqrt(2147395599));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
