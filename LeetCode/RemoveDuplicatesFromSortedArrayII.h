//
//  RemoveDuplicatesFromSortedArrayII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/08.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_RemoveDuplicatesFromSortedArrayII_h
#define LeetCode_RemoveDuplicatesFromSortedArrayII_h
class RemoveDuplicatesFromSortedArrayII {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) {
            return n;
        }
        int pos1 = 0, pos2 = 1, i, duplicate = 1;
        for (i = 2; i < n; i ++) {
            if (A[pos1] == A[i] && A[pos2] == A[i]) {
                continue;
            }
            pos1 ++;
            pos2 ++;
            A[pos2] = A[i];
        }
        return pos2 + 1;
    }
};
class RemoveDuplicatesFromSortedArrayIITest {
public:
    void test() {
        RemoveDuplicatesFromSortedArrayII s;
        int a[] = {1,1,1,1,2,2,2,3};
        int n = s.removeDuplicates(a, sizeof(a)/sizeof(int));
        for (int i = 0; i < n; i ++) {
            cout << a[i] << endl;
        }
    }
};
#endif
