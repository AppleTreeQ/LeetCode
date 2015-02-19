//
//  BestTimeToBuyAndSellStockII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/19.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#ifndef LeetCode_BestTimeToBuyAndSellStockII_h
#define LeetCode_BestTimeToBuyAndSellStockII_h
class BestTimeToBuyAndSellStockII {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 1)
            return 0;
        int size = prices.size();
        int *diff = new int[size];
        int maxprofit = 0;
        memset(diff, 0, sizeof(int)*size);
        //5,2,1,4,2,2,1,5
        diff[0] = 0;
        for (int i = 1; i < size; i ++) {
            diff[i] = prices[i] - prices[i - 1];
        }
        for (int i = 0; i < size; i ++) {
            if (diff[i] > 0)
                maxprofit += diff[i];
        }
        return maxprofit;
    }
};
class BestTimeToBuyAndSellStockIITest {
public:
    void test() {
        BestTimeToBuyAndSellStockII s;
        vector<int> prices;
        prices.push_back(5);
        prices.push_back(2);
        prices.push_back(1);
        prices.push_back(4);
        prices.push_back(2);
        prices.push_back(2);
        prices.push_back(1);
        prices.push_back(5);
        cout << s.maxProfit(prices) << endl;
    }
};
#endif
