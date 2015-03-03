//
//  SingleNumberII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/28.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SingleNumberII_h
#define LeetCode_SingleNumberII_h
class SingleNumberII {
public:
    int singleNumber(int A[], int n) {
        int count [32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i ++) {
            for (int j = 0; j < n; j ++) {
                count[i] += (A[j] >> i & 1);
            }
            result |= (count[i] % 3) << i;
        }
        return result;
    }
};
class SingleNumberIITest {
public:
    void test() {
        SingleNumberII s;
        int a[] = {2,2,2,3};
        cout << s.singleNumber(a, 4) << endl;
    }
};
#endif
