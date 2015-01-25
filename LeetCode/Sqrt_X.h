//
//  Sqrt_X.h
//  LeetCode
//
//  Created by ipuser on 2015/01/26.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//
/*
 Implement int sqrt(int x).
 
 Compute and return the square root of x.
 
 */
#ifndef LeetCode_Sqrt_X_h
#define LeetCode_Sqrt_X_h
class Sqrt_X {
public:
    int sqrt(int x) {
        if (x <= 0)
            return 0;
        long res = 1, temp = -1, min = -2, max = -1;
        while (1) {
            if (res * res < x) {
                min = res;
                if (max == -1)
                    res <<= 1;
            }
            else if (res * res == x)
                return res;
            else {
                max = res;
            }
            if (min != -2 && max != -1)
                res = (min + max) >> 1;
            if (res == min) {
                break;
            }
        }
        return res;
    }
};
class Sqrt_XTest {
public:
    void test() {
        Sqrt_X s;
        int res = s.sqrt(2147395599);
        cout << res << endl;
    }
};
#endif
