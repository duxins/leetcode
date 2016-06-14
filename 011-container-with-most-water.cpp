//  11. Container With Most Water
//  
//  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines
//  are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
//  forms a container, such that the container contains the most water.
//
//  Note: You may not slant the container.
//
//  Tags: Array, Two Pointers
//  
//  https://leetcode.com/problems/container-with-most-water/    

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = INT_MIN;
        int i = 0, j = height.size() - 1;

        while(i < j){
            int area = min(height[i], height[j]) * (j - i);
            result = max(result, area);

            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
};

TEST(leetcode_011_container_with_most_water, Basic)
{
    Solution solution = Solution();
    vector<int> height = {1, 2};
    EXPECT_EQ(1, solution.maxArea(height));

    height = {1, 2, 1};
    EXPECT_EQ(2, solution.maxArea(height));

    height = {1, 2, 4, 3};
    EXPECT_EQ(4, solution.maxArea(height));

    height = {76,155,15,188,180,154,84,34,187,142,22,5,27,183,111,128,50,58,2,112,179,2,100,111,115,76,134,120,118,103,31,
              146,58,198,134,38,104,170,25,92,112,199,49,140,135,160,20,185,171,23,98,150,177,198,61,92,26,147,164,144,51,
              196,42,109,194,177,100,99,99,125,143,12,76,192,152,11,152,124,197,123,147,95,73,124,45,86,168,24,34,133,120,
              85,81,163,146,75,92,198,126,191};

    EXPECT_EQ(18048, solution.maxArea(height));

    height = {75,21,3,152,13,107,163,166,32,160,41,131,7,67,56,5,153,176,29,139,61,149,176,142,64,75,170,156,73,48,148,101,
              70,103,53,83,11,168,1,195,81,43,126,88,62,134,45,167,63,26,107,124,128,83,67,192,158,189,149,184,37,49,85,107,
              152,90,143,115,58,144,62,139,139,189,180,153,75,177,121,138,4,28,15,132,63,82,124,174,23,25,110,60,74,147,120,
              179,37,63,94,47};

    EXPECT_EQ(14608, solution.maxArea(height));

    height = {159,157,139,51,98,71,4,125,48,125,64,4,105,79,136,169,113,13,95,88,190,5,148,17,152,20,196,141,35,42,188,147,
              199,127,198,49,150,154,175,199,80,191,3,137,22,92,58,87,57,153,175,199,110,75,16,62,96,12,3,83,55,144,30,6,23,
              28,56,174,183,183,173,15,126,128,104,148,172,163,35,181,68,162,181,179,37,197,193,85,10,197,169,17,141,199,
              175,164,180,183,90,115};
    EXPECT_EQ(15423, solution.maxArea(height));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
