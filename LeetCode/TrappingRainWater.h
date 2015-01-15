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
class TrappingRainWater {
public:
    int trap(int A[], int n) {
        if (n < 3)
            return 0;
        int up1 = 0; down = 0; up2 = 0;
        for (int i = 0; i < n; i ++) {
            if(up1) {
                ;
            }
            
        }
    }
};
class TrappingRainWaterTest {
public:
    void test() {
        
    }
};
#endif
