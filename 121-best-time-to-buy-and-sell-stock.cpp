//  121. Best Time to Buy and Sell Stock
//  
//  Say you have an array for which the ith element is the price of a given stock on day i.
//  If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//  Subscribe to see which companies asked this question
//  
//  Tags: Array, Dynamic Programming
//  
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min = INT_MAX;
        for(int price: prices){
            min = price < min ? price : min;
            if(price - min > profit){
                profit = price - min;
            }
        }
        return profit;
    }
};


TEST(leetcode_121_best_time_to_buy_and_sell_stock, Basic)
{
    Solution *solution = new Solution();
    vector<int> prices = {1, 2, 3, 4};
    EXPECT_EQ(3, solution->maxProfit(prices));

    prices = {8, 8, 8, 8, 8};
    EXPECT_EQ(0, solution->maxProfit(prices));

    prices = {4, 3, 2, 1};
    EXPECT_EQ(0, solution->maxProfit(prices));

    prices = {1, 18, 20};
    EXPECT_EQ(19, solution->maxProfit(prices));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
