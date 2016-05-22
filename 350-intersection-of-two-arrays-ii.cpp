//  350. Intersection of Two Arrays II
//  
//  Given two arrays, write a function to compute their intersection.
//
//  Example:
//  Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
//
//  Note:
//  Each element in the result should appear as many times as it shows in both arrays.
//  The result can be in any order.
//
//  Follow up:
//  What if the given array is already sorted? How would you optimize your algorithm?
//  What if nums1's size is small compared to num2's size? Which algorithm is better?
//  What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
//
//  Tags: Binary Search, Hash Table, Two Pointers, Sort
//  
//  https://leetcode.com/problems/intersection-of-two-arrays-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i]] ++;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(m[nums2[i]] > 0){
                m[nums2[i]]--;
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

TEST(leetcode_350_intersection_of_two_arrays_ii, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    EXPECT({2, 2}, solution->intersect(nums1, nums2));

    nums1 = {1, 1};
    nums2 = {1};
    EXPECT({1}, solution->intersect(nums1, nums2));

    nums1 = {1};
    nums2 = {1, 1, 2, 3};
    EXPECT({1}, solution->intersect(nums1, nums2));

    nums1 = {1, 2};
    nums2 = {3, 4};
    EXPECT({}, solution->intersect(nums1, nums2));

    nums1 = {4,7,9,7,6,7};
    nums2 = {5,0,0,6,1,6,2,2,4};
    EXPECT({4, 6}, solution->intersect(nums1, nums2));

    nums1 = {61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,
             67,34,62,35,47,98,3,41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,82,66,98,6,92,31,43,81,
             88,60,10,55,66,82,0,79,11,81};
    nums2 = {5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,16,6,99,0,2,36,68,52,73,50,77,44,61,48};
    EXPECT({5,4,57,79,7,89,88,45,34,92,38,85,6,0,77,44,61}, solution->intersect(nums1, nums2));

    nums1 = {43,85,49,2,83,2,39,99,15,70,39,27,71,3,88,5,19,5,68,34,7,41,84,2,13,85,12,54,7,9,13,19,92};
    nums2 = {10,8,53,63,58,83,26,10,58,3,61,56,55,38,81,29,69,55,86,23,91,44,9,98,41,48,41,16,42,72,6,4,2,81,42,84,4,13};
    EXPECT({2,83,3,41,84,13,9}, solution->intersect(nums1, nums2));

    nums1 = {54,93,21,73,84,60,18,62,59,89,83,89,25,39,41,55,78,27,65,82,94,61,12,38,76,5,35,6,51,48,61,0,47,60,84,9,13,
             28,38,21,55,37,4,67,64,86,45,33,41};
    nums2 = {17,17,87,98,18,53,2,69,74,73,20,85,59,89,84,91,84,34,44,48,20,42,68,84,8,54,66,62,69,52,67,27,87,49,92,14,
             92,53,22,90,60,14,8,71,0,61,94,1,22,84,10,55,55,60,98,76,27,35,84,28,4,2,9,44,86,12,17,89,35,68,17,41,21,65,
             59,86,42,53,0,33,80,20};
    EXPECT({54,21,73,84,60,18,62,59,89,89,41,55,27,65,94,61,12,76,35,48,0,60,84,9,28,55,4,67,86,33}, solution->intersect(nums1, nums2));

    nums1 = {93,57,18,68,93,31,36,11,27,82,3,91,58,36,21,26,72,53,15,9,56,68,89,37,54,40,87,61,82,24,8,68,80,36,31,11,51,
             45,66,78,70,93,44,45,19,23};
    nums2 = {24,30,85,26,19,82,20,92,34,31,15,43,83,40,15,0,87,60,11,2,0,26,49,14,19,18,55,21,96,68,30,50,11,59,8,89,51,
             59,76,16,59,28,88,3,87,94,0,36,70,80,8,65,84,88,28,91,96};
    EXPECT({18,68,31,36,11,82,3,91,21,26,15,89,40,87,24,8,80,11,51,70,19}, solution->intersect(nums1, nums2));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
