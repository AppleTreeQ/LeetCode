//
//  MergeSortedArray.h
//  LeetCode
//
//  Created by ipuser on 2015/02/11.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 
 Note:
 You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
#ifndef LeetCode_MergeSortedArray_h
#define LeetCode_MergeSortedArray_h
class MergeSortedArray {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n == 0)
            return;
        int indexa = m - 1, indexb = n - 1, index = m + n - 1;
        while (indexa >= 0 && indexb >= 0) {
            if (A[indexa] >= B[indexb]) {
                A[index] = A[indexa];
                indexa --;
                
            } else {
                A[index] = B[indexb];
                indexb --;
            }
            index --;
        }
        if (indexa < 0)
            for (int i = indexb; i >= 0; i --) {
                A[index] = B[i];
                index --;
            }
        if (indexb < 0)
            for (int i = indexa; i >= 0; i --) {
                A[index] = A[i];
                index --;
            }
        return;
    }
};
class MergeSortedArrayTest {
public:
    void test() {
        
    }
};
#endif
