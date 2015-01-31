//
//  ClimbingStairs.h
//  LeetCode
//
//  Created by ipuser on 2015/01/31.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
#ifndef LeetCode_ClimbingStairs_h
#define LeetCode_ClimbingStairs_h
class ClimbingStairs {
public:
    int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        int * a = new int[n];
        memset(a, 0, n * sizeof(int));
        a[0] = 1;
        for (int i = 1; i < n; i ++) {
            if(i > 1)
                a[i] = a[i - 1] + a[i - 2];
            else
                a[i] = a[i - 1] + 1;
        }
        return a[n - 1];
    }
    int helper(int start, int n) {
        if (start > n)
            return 0;
        if (start == n)
            return 1;
        return helper(start + 1, n) + helper(start + 2, n);
    }
    
};
class ClimbingStairsTest {
public:
    void test() {
        ClimbingStairs s;
        //1134903170
        cout << s.climbStairs(44) << endl;
    }
};
#endif
