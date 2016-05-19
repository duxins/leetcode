//  349. Intersection of Two Arrays
//  
//  Given two arrays, write a function to compute their intersection.
//  Example:
//  Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//  Note:
//  Each element in the result must be unique.
//  The result can be in any order.
//
//  Tags: Binary Search, Hash Table, Two Pointers, Sort
//  
//  https://leetcode.com/problems/intersection-of-two-arrays/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i]] = 1;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(m[nums2[i]] == 1){
                m[nums2[i]] = 2;
                result.push_back(nums2[i]);
            }
        }

        return result;
    }
};

void EXPECT(vector<int> expected, vector<int>result){
    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

TEST(leetcode_349_intersection_of_two_arrays, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    EXPECT({2}, solution->intersection(nums1, nums2));

    nums1 = {1, 1};
    nums2 = {1};
    EXPECT({1}, solution->intersection(nums1, nums2));

    nums1 = {1};
    nums2 = {1, 1, 2, 3};
    EXPECT({1}, solution->intersection(nums1, nums2));

    nums1 = {1, 2, 3, 4, 5};
    nums2 = {2, 2, 4, 5, 6, 7};
    EXPECT({2, 4, 5}, solution->intersection(nums1, nums2));

    nums1 = {1, 2};
    nums2 = {3, 4};
    EXPECT({}, solution->intersection(nums1, nums2));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
