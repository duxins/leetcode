//  347. Top K Frequent Elements
//  
//  Given a non-empty array of integers, return the k most frequent elements.
//
//  For example,
//  Given [1,1,1,2,2,3] and k = 2, return [1,2].
//  Note: 
//  You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//  Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//
//  Tags: Hash Table, Heap
//  
//  https://leetcode.com/problems/top-k-frequent-elements/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int n : nums){
            m[n]++;
        }

        vector<pair<int, int>> heap;
        for (auto &x : m) {
            heap.push_back(make_pair(x.second, x.first));
        }

        vector<int> result;
        make_heap(heap.begin(), heap.end());

        while(k--){
            result.push_back(heap.front().second);
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }

        return result;
    }
};


void EXPECT(vector<int> expected, vector<int> result){
    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}



TEST(leetcode_347_top_k_frequent_elements, Basic)
{
    Solution *solution = new Solution();
    vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    EXPECT({1,2,5,3,7,6,4,8,10,11}, solution->topKFrequent(nums, 10));

    nums = {1,1,1,2,2,3};
    EXPECT({1, 2}, solution->topKFrequent(nums, 2));

    nums = {5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2,-4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,
           -1,4,2,8,-3,5,-9,-3,6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,-4,-1,-1,6,-8,-9,-1,9,-9,
            3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5};
    EXPECT({4,-1,2,-5,-8,8,0}, solution->topKFrequent(nums, 7));

};

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
