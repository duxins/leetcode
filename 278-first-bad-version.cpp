//  278. First Bad Version
//  
//  You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad. 
//  Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//  You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
//
//  Tags: Binary Search
//  
//  https://leetcode.com/problems/first-bad-version/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i < j) {
            int mid = i + (j - i)/2;
            if (isBadVersion(mid)) {
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return j;
    }
};

int gFirstBadVersion = 0;

bool isBadVersion(int version){
    if (version >= ::gFirstBadVersion){
        return true;
    }
    return false;
}

TEST(leetcode_278_first_bad_version, Basic)
{
    Solution *solution = new Solution();

    ::gFirstBadVersion = 1702766719;
    EXPECT_EQ(1702766719, solution->firstBadVersion(2126753390));

    ::gFirstBadVersion = 1;
    EXPECT_EQ(1, solution->firstBadVersion(1));

    ::gFirstBadVersion = 10;
    EXPECT_EQ(10, solution->firstBadVersion(1000));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
