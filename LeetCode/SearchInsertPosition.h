//
//  SearchInsertPosition.h
//  LeetCode
//
//  Created by ipuser on 2015/01/05.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 */
#ifndef LeetCode_SearchInsertPosition_h
#define LeetCode_SearchInsertPosition_h
class SearchInsertPosition {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0)
            return 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (A[m] == target) return m;
            if (A[m] < target) {
                l = m + 1;
                if (l > r)
                    return l;
            }
            else
            {
                r = m - 1;
                if (l > r) {
                    return r + 1;
                }
            }
            
        }
        return 0;
    }
};
class SearchInsertPositionTest {
public:
    void test() {
        int a[] = {1,3,5,6};
        SearchInsertPosition solution;
        int res = solution.searchInsert(a, sizeof(a)/sizeof(int), 0);
        cout << res << endl;
    }
};
#endif
