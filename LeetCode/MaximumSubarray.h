//
//  MaximumSubarray.h
//  LeetCode
//
//  Created by ipuser on 2015/01/21.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */
#ifndef LeetCode_MaximumSubarray_h
#define LeetCode_MaximumSubarray_h
class MaximumSubarray {
public:
    int maxSubArray(int A[], int n) {
        int max = A[0], sum = 0;
        if (n == 1) {
            return max;
        }
        for (int range = 1; range <= n; range ++) {
            sum = 0;
            for (int j = 0; j < range; j ++) {
                sum += A[j];
            }
            max = max > sum ? max : sum;
            for (int j = range; j < n; j ++) {
                sum -= A[j - range];
                sum += A[j];
                max = max > sum ? max : sum;
            }
        }
        return max;
    }
};
class MaximumSubarrayTest {
public:
    void test() {
        MaximumSubarray s;
        int A[] = {-1, -2, -3};// {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int res = s.maxSubArray(A, sizeof(A)/sizeof(int));
        cout << res << endl;
    }
};
#endif
