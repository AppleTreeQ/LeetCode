//
//  RemoveDuplicatesFromSortedArray.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_RemoveDuplicatesFromSortedArray_h
#define LeetCode_RemoveDuplicatesFromSortedArray_h
class RemoveDuplicatesFromSortedArray {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
            return n;
        int pos = 0, i;
        for (i = 0; i < n - 1; i ++) {
            if (A[i] == A[i + 1])
                continue;
            pos ++;
            A[pos] = A[i + 1];
        }
        return pos + 1;
    }
};
class RemoveDuplicatesFromSortedArrayTest {
public:
    void test() {
        int a[] = {1, 1};
        RemoveDuplicatesFromSortedArray solution;
        cout << solution.removeDuplicates(a, sizeof(a)/sizeof(int)) << endl;
    }
};
#endif
