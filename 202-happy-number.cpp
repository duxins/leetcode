//  202. Happy Number
//  
//  Write an algorithm to determine if a number is "happy".
//  A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//  Example: 19 is a happy number
//
//  12 + 92 = 82
//  82 + 22 = 68
//  62 + 82 = 100
//  12 + 02 + 02 = 1
//
//  Tags: Hash Table, Math
//  
//  https://leetcode.com/problems/happy-number/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        int sum = 0;
        while(true){
            int sum = 0;
            int k = n;
            while(k){
                sum += (k%10) * (k%10);
                k /= 10;
            }
            if(sum == 1) return true;
            if(m.find(n) != m.end()) return false;
            m[n] = sum;
            n = sum;
        }
    }
};

TEST(leetcode_202_happy_number, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isHappy(1));
    EXPECT_TRUE(solution->isHappy(19));
    EXPECT_TRUE(solution->isHappy(91));
    EXPECT_TRUE(solution->isHappy(10000009));
    EXPECT_FALSE(solution->isHappy(0));
    EXPECT_FALSE(solution->isHappy(18));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
