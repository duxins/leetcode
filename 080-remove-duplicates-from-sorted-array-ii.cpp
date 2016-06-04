//  80. Remove Duplicates from Sorted Array II
//  
//  Follow up for "Remove Duplicates":
//  What if duplicates are allowed at most twice?
//  For example,
//  Given sorted array nums = [1,1,1,2,2,3],
//  Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
//
//  Tags: Array, Two Pointers
//  
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int i = 2;
        for(int j = 2; j < nums.size(); j++){
            if(nums[j] > nums[i - 2]){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

void EXPECT(vector<int> expected,vector<int> nums)
{
    Solution *solution = new Solution();
    int length = solution->removeDuplicates(nums);
    vector<int> result (nums.begin(), nums.begin() + length);
    EXPECT_EQ(expected.size(), length);
    EXPECT_EQ(expected, result);
}


TEST(leetcode_080_remove_duplicates_from_sorted_array_ii, Basic)
{
    EXPECT({1}, {1});
    EXPECT({1, 1}, {1, 1});
    EXPECT({1, 1}, {1, 1, 1});
    EXPECT({1, 1, 2}, {1, 1, 2});
    EXPECT({1, 1, 2, 2, 3}, {1, 1, 1, 2, 2, 3});
    EXPECT({0,0,1,2,2,3,3,4,4}, {0,0,0,0,0,1,2,2,3,3,4,4});
    EXPECT({-50,-50,-49,-48,-47,-47,-46,-45,-43,-42,-41,-40,-40,-39,-38,-38,-37,-36,-35,-34,-34,-33,-32,-31,-30,-28,-27,-26,-26,-25,-25,-24,-24,-22,-22,-21,-21,-20,-19,-18,-18,-17,-17,-16,-16,-15,-14,-14,-13,-13,-12,-12,-10,-10,-9,-8,-8,-7,-7,-6,-5,-4,-4,-3,-1,1,2,2,3,4,5,6,6,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,16,17,17,18,20,21,22,22,23,23,25,26,28,29,29,30,31,31,32,33,34,34,36,36,37,37,38,38,39,40,40,41,42,42,43,43,44,44,45,45,46,47,47,48,49,49,50},
           {-50,-50,-49,-48,-47,-47,-47,-46,-45,-43,-42,-41,-40,-40,-40,-40,-40,-40,-39,-38,-38,-38,-38,-37,-36,-35,-34,-34,-34,-33,-32,-31,-30,-28,-27,-26,-26,-26,-25,-25,-24,-24,-24,-22,-22,-21,-21,-21,-21,-21,-20,-19,-18,-18,-18,-17,-17,-17,-17,-17,-16,-16,-15,-14,-14,-14,-13,-13,-12,-12,-10,-10,-9,-8,-8,-7,-7,-6,-5,-4,-4,-4,-3,-1,1,2,2,3,4,5,6,6,7,8,8,9,9,10,10,10,11,11,12,12,13,13,13,14,14,14,15,16,17,17,18,20,21,22,22,22,23,23,25,26,28,29,29,29,30,31,31,32,33,34,34,34,36,36,37,37,38,38,38,39,40,40,40,41,42,42,43,43,44,44,45,45,45,46,47,47,47,47,48,49,49,49,50});
    EXPECT({-3,-1,-1,0,0,2}, {-3,-1,-1,0,0,0,0,0,2});
    EXPECT({0,0,1,1,2,2,3,3,4}, {0,0,1,1,1,2,2,2,3,3,4});
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
