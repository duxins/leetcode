//  88. Merge Sorted Array
//  
//  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//  Note:
//  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//  The number of elements initialized in nums1 and nums2 are m and n respectively.
//
//  Tags: Array, Two Pointers
//  
//  https://leetcode.com/problems/merge-sorted-array/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k=  m + n - 1;

        while(k >= 0){
            if(i >=0 && j >= 0){
                nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
            }else {
                nums1[k--] = (j < 0) ? nums1[i--] : nums2[j--];
            }
        }
    }
};

TEST(leetcode_088_merge_sorted_array, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    solution->merge(nums1, 0, nums2, 1);
    EXPECT_EQ(vector<int>({1}), nums1);

    nums1 = {1, 3, 4, 0, 0, 0};
    nums2 = {2, 5, 6};
    solution->merge(nums1, 3, nums2, 3);
    EXPECT_EQ(vector<int>({1, 2, 3, 4, 5, 6}), nums1);

    nums1 = {0, 0, 0};
    nums2 = {2, 5, 6};
    solution->merge(nums1, 0, nums2, 3);
    EXPECT_EQ(vector<int>({2, 5, 6}), nums1);

    nums1 = {4, 5, 6, 0, 0, 0};
    nums2 = {1, 2, 3};
    solution->merge(nums1, 3, nums2, 3);
    EXPECT_EQ(vector<int>({1, 2, 3, 4, 5, 6}), nums1);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
