//
//  ReverseInteger.h
//  LeetCode
//
//  Created by ipuser on 2014/12/22.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_ReverseInteger_h
#define LeetCode_ReverseInteger_h
#include <iostream>
#include <limits.h>
using namespace std;

class ReverseInteger {
public:
    int reverse(int x) {
        int left=0, result = 0;
        bool isNeg = x > 0 ? false : true;
        if (isNeg)
            x = abs(x);
        int a = INT_MAX;
        while(x > 0) {
            left = x % 10;
            if (result != 0) {
                 double b = (double)a / result;
                if( b < 10)
                    return 0;
            }
            result = result * 10 + left;
            x = x / 10;
        }
        if (result < 0)
            return -1;
        if (isNeg)
            return result * (-1);
        return result;
    }
};
class ReverseIntegerTest {
public:
    void test() {
        ReverseInteger solution;
        cout << solution.reverse(32768) << endl;
        return;
    }
};

#endif
