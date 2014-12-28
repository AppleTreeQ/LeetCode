//
//  RomantoInteger.h
//  LeetCode
//
//  Created by ipuser on 2014/12/28.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_RomantoInteger_h
#define LeetCode_RomantoInteger_h
#include <iostream>
#include <string>
#include "IntegertoRoman.h"
using namespace std;

class RomantoInteger {
public:
    int romanToInt(string s) {
        string romanNum[4][3] = {
            {"I","V","X"},
            {"X","L","C"},
            {"C","D","M"},
            {"M","S","B"}
        };
        int size = s.size(), result = 0;
        char lastChar;
        for (int i =  size -1 ; i >= 0; i --) {
            if ( s[i] == 'I') {
                if (lastChar == 'V' || lastChar == 'X')
                    result -= 1;
                else
                    result += 1;
                lastChar = 'I';
            }
            if ( s[i] == 'V' ) {
                result += 5;
                lastChar = 'V';
            }
            if ( s[i] == 'X' ) {
                if (lastChar == 'L' || lastChar == 'C')
                    result -= 10;
                else
                    result += 10;
                lastChar = 'X';
            }
            if ( s[i] == 'L' ) {
                result += 50;
                lastChar = 'L';
            }
            if ( s[i] == 'C' ) {
                if (lastChar == 'D' || lastChar == 'M')
                    result -= 100;
                else
                    result += 100;
                lastChar = 'C';
            }
            if ( s[i] == 'D' ) {
                    result += 500;
                    lastChar = 'D';
            }
            if ( s[i] == 'M' ) {
                    result += 1000;
                    lastChar = 'M';
            }
        }
        return result;
    }
};
class RomantoIntegerTest {
public:
    void test() {
        IntegertoRoman itr;
        RomantoInteger rti;
        for (int i = 1; i < 4000; i ++) {
            string re = itr.intToRoman(i);
            cout << i << ", " << re << ", " << rti.romanToInt(re) << endl;
        }
    }
};
#endif
