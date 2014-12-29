//
//  RemoveElement.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_RemoveElement_h
#define LeetCode_RemoveElement_h
class RemoveElement {
public:
    int removeElement(int A[], int n, int elem) {
        int counter = 0;
        for (int i = 0; i < n; i ++) {
            if (A[i] != elem) {
                A[counter] = A[i];
                counter ++;
            }
        }
        return counter;
    }
};
class RemoveElementTest {
public:
    void test() {
        int a[] = {1,1,4,5,2,3,5,8,3,4,1};
        RemoveElement solution;
        cout << solution.removeElement(a, sizeof(a)/sizeof(int), 1) << endl;
    }
};
#endif
