//
//  FirstMissingPositive.h
//  LeetCode
//
//  Created by ipuser on 2015/01/13.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an unsorted integer array, find the first missing positive integer.
 
 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 
 Your algorithm should run in O(n) time and uses constant space.
 */
#ifndef LeetCode_FirstMissingPositive_h
#define LeetCode_FirstMissingPositive_h
class FirstMissingPositive {
public:
    int firstMissingPositive(int A[], int n) {
        int res = 0, i = 0;
        for (; i < n; ) {
            if(A[i] <= n && A[A[i]-1] != A[i]) {
                swap(A[A[i]-1], A[i]);
            } else
                i ++;
        }
        for (i = 0; i < n; i ++) {
            if((A[i]-1) != i) {
                res = i + 1;
                break;
            }
        }
        if (i == n)
            return n + 1;
        return res;
    }
    void swap(int &a, int &b) {
        int c;
        c = a;
        a = b;
        b = c;
    }
};
class FirstMissingPositiveTest {
public:
    void test() {
        FirstMissingPositive solution;
        int a[] = {};
        int res = solution.firstMissingPositive(a, sizeof(a)/sizeof(int));
        cout << res << endl;
    }
};
#endif
