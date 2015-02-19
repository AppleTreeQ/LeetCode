//
//  BestTimeToBuyAndSellStock.h
//  LeetCode
//
//  Created by ipuser on 2015/02/18.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
#ifndef LeetCode_BestTimeToBuyAndSellStock_h
#define LeetCode_BestTimeToBuyAndSellStock_h
class BestTimeToBuyAndSellStock {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 1)
            return 0;
        int size = prices.size();
        int minPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < size; i ++) {
            profit = (prices[i]-minPrice) > profit ? (prices[i]-minPrice) : profit;
            minPrice = minPrice < prices[i] ? minPrice : prices[i];
        }
        return profit;
    }
};
class BestTimeToBuyAndSellStockTest {
public:
    void test() {
        
    }
};
#endif
