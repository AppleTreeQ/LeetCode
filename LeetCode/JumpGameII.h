//
//  JumpGameII.h
//  LeetCode
//
//  Created by ipuser on 2015/01/17.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Your goal is to reach the last index in the minimum number of jumps.
 
 For example:
 Given array A = [2,3,1,1,4]
 
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
#ifndef LeetCode_JumpGameII_h
#define LeetCode_JumpGameII_h
class JumpGameII {
public:
    int jump(int A[], int n) {
        if (n < 2) {
            return 0;
        }
        int start = 0, end = 0, step = 0, maxRange = 0;
        while (end < n) {
	    maxRange = start + A[start];
            for (int i = start; i <= end; i ++) {
		if((i + A[i]) >= (n - 1)) {
	  	    step ++;
		    return step;
		}
		if (maxRange < (i + A[i])) {
		    maxRange = i + A[i];
		} 
	    }
	    step ++;
	    start = start + A[start] + 1;
	    end = maxRange; 
        }
    }
};
class JumpGameIITest {
public:
    void test() {
        JumpGameII s;
        int a[] = {1, 1, 1, 1};
        int step = s.jump(a, sizeof(a)/sizeof(int));
        cout << step << endl;
    }
};
/*
 二指针问题，最大覆盖区间。
 从左往右扫描，维护一个覆盖区间，每扫过一个元素，就重新计算覆盖区间的边界。比如，开始时区间[start, end], 遍历A数组的过程中，不断计算A[i]+i最大值（即从i坐标开始最大的覆盖坐标），并设置这个最大覆盖坐标为新的end边界。而新的start边界则为原end+1。不断循环，直到end> n.
 */
#endif
