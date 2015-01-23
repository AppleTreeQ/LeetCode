//
//  JumpGame.h
//  LeetCode
//
//  Created by ipuser on 2015/01/21.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Determine if you are able to reach the last index.
 
 For example:
 A = [2,3,1,1,4], return true.
 
 A = [3,2,1,0,4], return false.
 */
#ifndef LeetCode_JumpGame_h
#define LeetCode_JumpGame_h
class JumpGame {
public:
    bool canJump(int A[], int n) {
        int start = 0, end = 0, max;
        while (end < n) {
            max = start + A[start];
            for (int i = start; i <= end; i ++) {
                max = (i + A[i]) > max ? (i + A[i]) : max;
                if (max >= (n - 1))
                    return true;
            }
            start = end + 1;
            if (start > max) {
                return false;
            }
            end = max;
        }
        return true;
    }
};
class JumpGameTest {
public:
    void test() {
        JumpGame s;
        int a[] = {3,2,1,1,4};
        cout << s.canJump(a, sizeof(a) / sizeof(int)) << endl;
    }
};
#endif
