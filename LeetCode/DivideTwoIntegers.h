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
        if(divisor == 0)
        {
            return INT_MAX;
        }
        //bool isNeg = (dividend^divisor)>>31 == 1;
        bool isNeg;
        if ((divisor < 0 && dividend < 0) || (dividend > 0 && divisor > 0))
            isNeg = false;
        else
            isNeg = true;
        int res = 0;
        if(dividend == INT_MAX)
        {
            dividend += abs(divisor);
            if(divisor == -1)
            {
                return INT_MAX;
            }
            res++;
        }
        if(divisor == INT_MIN)
        {
            return res;
        }
        unsigned int dvd = dividend > 0 ? dividend : (-1)*dividend;
        unsigned int dvs = divisor > 0 ? divisor : (-1)*divisor;
        int digit = 0;
        while(dvs <= (dvd>>1))
        {
            dvs <<= 1;
            digit++;
        }
        while(digit>=0)
        {
            if(dvd>=dvs)
            {
                res += 1<<digit;
                dvd -= dvs;
            }  
            dvs >>= 1;
            digit--;  
        }  
        return isNeg?-res:res;
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
        cout << solution.divide(-2147483648, -1) << endl;
    }
};
#endif
