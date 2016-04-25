//  165. Compare Version Numbers
//  
//  Compare two version numbers version1 and version2.
//  If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//  You may assume that the version strings are non-empty and contain only digits and the . character.
//  The . character does not represent a decimal point and is used to separate number sequences.
//
//  For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//  Here is an example of version numbers ordering:
//  0.1 < 1.1 < 1.2 < 13.37
//
//  Tags: String
//  
//  https://leetcode.com/problems/compare-version-numbers/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int v1 = 0 , v2 = 0;

        while(i < version1.length() || j < version2.length()){
            v1 = 0;
            v2 = 0;
            while(i < version1.length() && version1[i] != '.'){
                v1 = v1 * 10 + (version1[i++] - '0');
            }

            while(j < version2.length() && version2[j] != '.'){
                v2 = v2 * 10 + (version2[j++] - '0');
            }

            if(v1 != v2) return (v1 > v2) ? 1 : -1;

            i++;
            j++;
        }
        return 0;
    }
};

TEST(leetcode_165_compare_version_numbers, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(1,  solution->compareVersion("1.1", "0.1"));
    EXPECT_EQ(-1, solution->compareVersion("1.1", "1.2"));
    EXPECT_EQ(-1, solution->compareVersion("1.2", "13.37"));
    EXPECT_EQ(-1, solution->compareVersion("1.2", "1.2.1"));
    EXPECT_EQ(0,  solution->compareVersion("1.2.1", "1.2.1"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
