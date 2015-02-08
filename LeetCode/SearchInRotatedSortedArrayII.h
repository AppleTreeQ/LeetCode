//
//  SearchInRotatedSortedArrayII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/08.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 
 duplicate exists in the array.
 */
#ifndef LeetCode_SearchInRotatedSortedArrayII_h
#define LeetCode_SearchInRotatedSortedArrayII_h
class SearchInRotatedSortedArrayII {
public:
    bool search(int A[], int n, int target) {
        bool res = false;
        
    }
};
class SearchInRotatedSortedArrayIITest {
public:
    void test() {
        int a[] = {3,1};
        SearchInRotatedSortedArrayII solution;
        int res = solution.search(a, sizeof(a)/sizeof(int), 1);
        cout << res << endl;
    }
};
#endif
