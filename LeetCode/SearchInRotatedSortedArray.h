//
//  SearchInRotatedSortedArray.h
//  LeetCode
//
//  Created by ipuser on 2015/01/05.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.
 */

#ifndef LeetCode_SearchInRotatedSortedArray_h
#define LeetCode_SearchInRotatedSortedArray_h
class SearchInRotatedSortedArray {
public:
    int search(int A[], int n, int target) {
        if (n == 0)
            return -1;
        if (n == 1)
            if (A[0] == target)
                return 0;
            else
                return -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r)/ 2;
            if (A[m] == target)
                return m;
            if (A[m] >= A[l]) { // 注意用>=，因为搜索到最后有可能m==l
                if (target <= A[m] && target >= A[l])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (target >= A[m] && target <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
    int search2(int A[], int n, int target){
        int l = 0, r = n-1;
        while(l<=r) {
            int m = (l+r)/2;
            if(A[m] == target) return m;
            if(A[m]>= A[l]) {
                if(A[l]<=target && target<= A[m])
                    r=m-1;
                else
                    l = m+1;
            } else {
                if(A[m] >= target || target>= A[l])
                    r = m-1;
                else
                    l = m+1;
            }
        }
        return -1;
    }
};
class SearchInRotatedSortedArrayTest {
public:
    void test() {
        int a[] = {3,1};
        SearchInRotatedSortedArray solution;
        int res = solution.search(a, sizeof(a)/sizeof(int), 1);
        cout << res << endl;
    }
};
#endif
