//  50. Pow(x, n)
//  
//  Implement pow(x, n).
//
//  Tags: Math, Binary Search
//  
//  https://leetcode.com/problems/powx-n/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == 2) return x * x;

        if(n < 0) return 1/x * myPow(1/x, abs(n + 1));

        if(n % 2 == 0){
            return myPow(myPow(x, n/2), 2);
        }else{
            return x * myPow(myPow(x, n/2), 2);
        }
    }
};

TEST(leetcode_050_powx_n, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(9.0,  solution->myPow(3.0, 2));
    EXPECT_EQ(0.25, solution->myPow(4.0, -1));
    EXPECT_EQ(27.0, solution->myPow(3.0, 3));
    EXPECT_EQ(1.0,  solution->myPow(1.0, -2147483648));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
