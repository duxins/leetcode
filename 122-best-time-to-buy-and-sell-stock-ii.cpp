//  122. Best Time to Buy and Sell Stock II
//  
//  Say you have an array for which the ith element is the price of a given stock on day i.
//  Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
//  However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//  Subscribe to see which companies asked this question
//  
//  Tags: Array, Greedy
//  
//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};

TEST(leetcode_122_best_time_to_buy_and_sell_stock_ii, Basic)
{
    Solution *solution = new Solution();
    vector<int> prices = {1, 2, 3, 4};
    EXPECT_EQ(3, solution->maxProfit(prices));

    prices = {4, 3, 2, 1};
    EXPECT_EQ(0, solution->maxProfit(prices));

    prices = {1, 2, 3};
    EXPECT_EQ(2, solution->maxProfit(prices));

    prices = {1, 100, 102};
    EXPECT_EQ(101, solution->maxProfit(prices));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
