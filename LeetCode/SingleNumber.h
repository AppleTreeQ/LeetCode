//
//  SingleNumber.h
//  LeetCode
//
//  Created by ipuser on 2015/01/09.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SingleNumber_h
#define LeetCode_SingleNumber_h
class SingleNumber {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < n; i ++) {
            res ^= A[i];
        }
        return res;
    }
};
class SingleNumberTest {
public:
    void test() {
        SingleNumber solution;
        int a[] = {-1,-1,0, 1, 1, 0, 3, 4, 4};
        int res = solution.singleNumber(a, sizeof(a)/sizeof(int));
        cout << res << endl;
    }
};
#endif
