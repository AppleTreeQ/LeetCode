//
//  SearchForARange.h
//  LeetCode
//
//  Created by ipuser on 2015/01/05.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a sorted array of integers, find the starting and ending position of a given target value.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */
#ifndef LeetCode_SearchForARange_h
#define LeetCode_SearchForARange_h
class SearchForARange {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        if (n == 0)
            return result;
        search(A, 0, n - 1, target, result);
        return result;
    }
    void search (int A[], int l, int r, int target, vector<int> &res) {
        if (l == r) {
            if(A[l] == target){
                if(res[0] == -1 || (res[0] != -1 && l < res[0]))
                    res[0] = l;
                if (res[1] == -1 || (res[1] != -1 && r > res[1]))
                    res[1] = r;
            }
            return;
        }
        int m = (l + r) / 2;
        search(A, l, m, target, res);
        search(A, m+1, r, target, res);
    }
};
class SearchForARangeTest {
public:
    void test() {
        int a[] = {8,8,9};
        SearchForARange solution;
        vector<int> res = solution.searchRange(a, sizeof(a)/sizeof(int), 8);
        cout << res[0] << ", " << res[1] << endl;
    }
};
#endif
