//  27. Remove Element
//  
//  Given an array and a value, remove all instances of that value in place and return the new length.
//  The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//  Subscribe to see which companies asked this question
//  
//  Tags: Array, Two Pointers
//  
//  https://leetcode.com/problems/remove-element/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

TEST(leetcode_027_remove_element, Basic)
{
    vector<int> nums {1, 2, 3, 2, 4};
    vector<int> expected {1, 3, 4};

    Solution *sol = new Solution();
    int count = sol->removeElement(nums, 2);
    EXPECT_EQ(3, count);

    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], nums[i]);
    }
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
