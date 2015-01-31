//
//  SortColors.h
//  LeetCode
//
//  Created by ipuser on 2015/01/31.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note:
 You are not suppose to use the library's sort function for this problem.
 follow up:
 
 */
#ifndef LeetCode_SortColors_h
#define LeetCode_SortColors_h
class SortColors {
public:
    void sortColors(int A[], int n) {
        int num0 = 0, num1 = 0, num2 = 0;
        for (int i = 0; i < n; i ++) {
            if (A[i] == 0)
                num0 ++;
            if (A[i] == 1)
                num1 ++;
            if (A[i] == 2)
                num2 ++;
        }
        for (int i = 0; i < n; i ++) {
            if (i < num0)
                A[i] = 0;
            else if (i < (num0 + num1))
                A[i] = 1;
            else
                A[i] = 2;
        }
    }
    void sortColors2(int A[], int n) {
        int index0 = 0, index2 = n - 1;
        for (int i = 0; i <=index2;) {
            if (A[i] == 0) {
                A[i] = A[index0];
                A[index0] = 0;
                index0 ++;
                i = index0 > i ? index0 : i;
                continue;
            }
            if (A[i] == 2) {
                A[i] = A[index2];
                A[index2] = 2;
                index2 --;
                continue;
            }
            i ++;
        }
    }
};
class SortColorsTest {
public:
    void test() {
        int a[] = {2, 1, 0, 1}; // 1, 2, 0, 2 -> 0, 2, 1, 2
        SortColors s;
        s.sortColors2(a, sizeof(a)/sizeof(int));
        for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
            cout << a[i] << ", ";
        }
        cout << endl;
    }
};
#endif
