//
//  MedianOfTwoSortedArrays.h
//  LeetCode
//
//  Created by ipuser on 2014/11/06.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

#ifndef LeetCode_MedianOfTwoSortedArrays_h
#define LeetCode_MedianOfTwoSortedArrays_h

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

class MedianTwoSortedArrays {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> merge;
        for ( int i = 0; i < m; i ++) {
            merge.push_back(A[i]);
        }
        for ( int i = 0; i < n; i ++) {
            merge.push_back(B[i]);
        }
        std::sort(merge.begin(), merge.end(), myfunction);
        if ( ( m + n ) % 2 ) {
            return merge.at( ( m + n ) / 2 );
        } else {
            return ( merge.at( ( m + n - 2 ) / 2 ) + merge.at( ( m + n ) / 2 )) / 2.0;
        }
    }
};
/*class MedianTwoSortedArrays2 {
public:
    double 
};*/
class MedianTwoSortedArraysTest {
public:
    void test() {
        int a[4] = {1, 3, 5, 9};
        int b[4] = {2, 4, 6, 8};
        MedianTwoSortedArrays median;
        cout << median.findMedianSortedArrays(a, 4, b, 4) << endl;
    }
};
#endif
