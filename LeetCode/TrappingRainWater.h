//
//  TrappingRainWater.h
//  LeetCode
//
//  Created by ipuser on 2015/01/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
#ifndef LeetCode_TrappingRainWater_h
#define LeetCode_TrappingRainWater_h
/*
 对每个数组中的数，求它的左边最高和右边最高，就知道自己的位置可以放多少水
 */
class TrappingRainWater {
public:
    int trap(int A[], int n) {
        if (n < 3)
            return 0;
        int *fromleftside = new int[n], *fromrightside = new int[n], res = 0;
        memset(fromleftside, 0, n * sizeof(int));
        memset(fromrightside, 0, n * sizeof(int));
        for(int i = 0; i < n; i ++) {
            if(i > 0) {
                fromleftside[i] = fromleftside[i - 1] > A[i - 1] ? fromleftside[i - 1] : A[i - 1];
                fromrightside[n - i - 1] = fromrightside[n - i] > A[n - i] ? fromrightside[n - i] : A[n - i];
            }
        }
        fromleftside[0] = 0;
        fromrightside[n - 1] = 0;
        for (int i = 0; i < n; i ++) {
            int height = fromleftside[i] < fromrightside[i] ? fromleftside[i] : fromrightside[i];
            res += height > A[i] ? (height - A[i]) : 0;
        }
        return res;
    }
};
class TrappingRainWaterTest {
public:
    void test() {
        TrappingRainWater solution;
        int a[] = {5,4,1,2};
        int res = solution.trap(a, sizeof(a)/sizeof(int));
        cout << res << endl;
    }
};
#endif
