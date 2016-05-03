//  223. Rectangle Area
//  
//  Find the total area covered by two rectilinear rectangles in a 2D plane.
//  Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//  Assume that the total area is never beyond the maximum possible value of int.
//
//  Tags: Math
//  
//  https://leetcode.com/problems/rectangle-area/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int trX = min(C, G);
        int trY = min(D, H);

        int blX = max(A, E);
        int blY = max(B, F);

        int overlap = 0;

        if(trX > blX && trY > blY){
            overlap = (trX - blX)  * (trY - blY);
        }

        return (C-A) * (D-B) + (G-E) * (H-F) -overlap;
    }
};

TEST(leetcode_223_rectangle_area, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ(8, solution->computeArea(1, 2, 3, 4, 5, 6, 7, 8));
    EXPECT_EQ(16, solution->computeArea(-2, -2, 2, 2, -2, -2, 2, 2));
    EXPECT_EQ(20, solution->computeArea(-2, -2, 2, 2, -1, 4, 1, 6));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
