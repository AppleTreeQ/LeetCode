//
//  BestTimeToBuyAndSellStockIII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/19.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#ifndef LeetCode_BestTimeToBuyAndSellStockIII_h
#define LeetCode_BestTimeToBuyAndSellStockIII_h
class BestTimeToBuyAndSellStockIII {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 1)
            return 0;
        int size = prices.size();
        vector<vector<int> > res(vector(size, 0), size);
        int maxprofit = 0;
        memset(diff, 0, sizeof(int)*size);
        //1,2,5,6,8
        diff[0] = 0;
        for (int i = 0; i < size; i ++) {
            for (int j = i; j < size; j ++) {
                
            }
            diff[i] = prices[i] - prices[i - 1];
        }
        for (int i = 0; i < size; i ++) {
            if (diff[i] > 0)
                maxprofit += diff[i];
        }
        return maxprofit;
    }
};
class BestTimeToBuyAndSellStockIIITest {
public:
    void test() {
        BestTimeToBuyAndSellStockIII s;
        vector<int> prices;
        prices.push_back(3);
        prices.push_back(3);
        prices.push_back(5);
        prices.push_back(0);
        prices.push_back(0);
        prices.push_back(3);
        prices.push_back(1);
        prices.push_back(4);
        cout << s.maxProfit(prices) << endl;
    }
};
#endif
