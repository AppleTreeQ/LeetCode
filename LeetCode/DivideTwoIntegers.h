//
//  DivideTwoIntegers.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_DivideTwoIntegers_h
#define LeetCode_DivideTwoIntegers_h
class DivideTwoIntegers {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        if (dividend == 0) {
            return 0;
        }
        bool isNeg = false;
        int result = -1;
        if ((divisor < 0 && dividend < 0) || (dividend > 0 && divisor > 0))
            isNeg = false;
        else
            isNeg = true;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= 0) {
            result ++;
            dividend -= divisor;
        }
        result = isNeg ? (-1)*result : result;
        return result;
    }
};
class DivideTwoIntegersTest {
public:
    void test() {
        DivideTwoIntegers solution;
        cout << solution.divide(INT_MIN, 100) << endl;
    }
};
#endif
