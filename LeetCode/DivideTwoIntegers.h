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
        int result = 1;
        if ((divisor < 0 && dividend < 0) || (dividend > 0 && divisor > 0))
            isNeg = false;
        else
            isNeg = true;
        unsigned int dvd = dividend > 0 ? dividend : (-1)*dividend;
        unsigned int dvs = divisor > 0 ? divisor : (-1)*divisor;
        unsigned int bak_dvs = dvs;
        if (dvs == 1) {
            result = isNeg ? (-1)*dvd : dvd;
            return result;
        }
        while ( dvd > dvs ) {
            dvs = dvs << 1;
            if (dvs <= dvd)
                result = result << 1;
        }
        dvs = dvs << 1;
        while (dvd > dvs) {
            dvs += bak_dvs;
            if (dvs <= dvd)
                result += 1;
            else
                break;
        }
        result = isNeg ? (-1)*result : result;
        return result;
    }
    int divide2(int dividend, int divisor) {
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
        cout << solution.divide(5, 2) << endl;
    }
};
#endif
