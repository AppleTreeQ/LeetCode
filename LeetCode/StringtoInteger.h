//
//  StringtoInteger.h
//  LeetCode
//
//  Created by ipuser on 2014/12/23.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

#ifndef LeetCode_StringtoInteger_h
#define LeetCode_StringtoInteger_h
#include <iostream>
#include <stdlib.h>
using namespace std;
class StringtoInteger {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
        const char *p = str;
        bool isNeg = false;
        while(*p == ' ') p++;
        int delta = *p - '0';
        if (delta == -3) {
            isNeg = true;
            p ++;
        }
        else if (delta == -5) {
            isNeg = false;
            p ++;
        }
        int result = 0;
        double times = 20;
        for (; *p != '\0'; p ++) {
            delta = *p - '0';
            if (!(delta >= 0 && delta <=9))
                return isNeg? (-1)*result:result;
            if(result != 0)
                times = (double)(INT_MAX-delta)/result;
            if (times < 10){
                result = isNeg? INT_MIN:INT_MAX;
                return result;
            } else
                result = result * 10 + delta;
        }
        result = isNeg?(-1)*result : result;
        return result;
    }
};
class StringtoIntegerTest {
public:
    void test() {
        StringtoInteger solution;
        char p[] = "    -2147aa483647";
        cout << atoi(p) << endl;
        int re = solution.atoi(p);
        cout << re << endl;
    }
};

#endif
