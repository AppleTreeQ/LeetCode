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
        int minprice = prices[0], maxprice = prices[size - 1], maxprofit1 = 0, maxprofit2 = 0;
        int *fromleftside = new int[size], *fromrightside = new int[size];
        memset(fromleftside, 0, sizeof(int) * size);
        memset(fromrightside, 0, sizeof(int) * size);
        fromleftside[0] = 0;
        fromrightside[size-1] = 0;
        //1,2,1,6,8
        for (int i = 1; i < size; i ++) {
            if ((prices[i] - minprice) > maxprofit1) {
                fromleftside[i] = prices[i] - minprice;
                maxprofit1 = prices[i] - minprice;
            }
            else{
                minprice = minprice < prices[i] ? minprice : prices[i];
                fromleftside[i] = maxprofit1;
            }
            if ((maxprice - prices[size-i-1]) > maxprofit2) {
                fromrightside[size-i-1] = maxprice - prices[size-i-1];
                maxprofit2 = maxprice - prices[size-i-1];
            } else {
                fromrightside[size-i-1] = maxprice - prices[size-i-1];;
                maxprice = maxprice > prices[size-i-1] ? maxprice : prices[size-i-1];
            }
        }
        maxprofit1 = 0;
        for (int i = 0; i < size; i ++) {
            maxprofit1 = maxprofit1 > (fromleftside[i] + fromrightside[i]) ? maxprofit1 : (fromleftside[i] + fromrightside[i]);
        }
        delete[] fromleftside;
        delete[] fromrightside;
        return maxprofit1;
    }
};
class BestTimeToBuyAndSellStockIIITest {
public:
    void test() {
        BestTimeToBuyAndSellStockIII s;
        vector<int> prices;
        prices.push_back(2);
        prices.push_back(1);
        prices.push_back(2);
        prices.push_back(0);
        prices.push_back(1);
        // 2,1,2,0,1
        //0,0,1,1
        cout << s.maxProfit(prices) << endl;
    }
};
#endif
