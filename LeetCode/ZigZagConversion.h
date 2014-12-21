//
//  ZigZagConversion.h
//  LeetCode
//
//  Created by ipuser on 2014/12/22.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

#ifndef LeetCode_ZigZagConversion_h
#define LeetCode_ZigZagConversion_h
#include<iostream>
#include<string>
using namespace std;

class ZigZagConversion {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        string *pStr = new string[nRows];
        int num = 2 * nRows - 2;
        for (int j = 0; j < s.length(); j ++) {
            int rem = j % num;
            if ( rem < nRows ) {
                pStr[rem] += s[j];
            } else {
                pStr[2*nRows - 2 - rem] += s[j];
            }
        }
        string result;
        for(int i = 0; i < nRows; i ++) {
            result += pStr[i];
        }
        delete[] pStr;
        return result;
    }
};

class ZigZagConversionTest {
public:
    void test() {
        string s = "vucftpwctgtwmxnupycfgcuqunublmoiitncklefszbexrampetvhqnddjeqvuygpnkazqfrpjvoaxdpcwmjobmskskfojnewxgxnnofwltwjwnnvbwjckdmeouuzhyvhgvwujbqxxpitcvograiddvhrrdsycqhkleewhxtembaqwqwpqhsuebnvfgvjwdvjjafqzzxlcxdzncqgjlapopkvxfgvicetcmkbljopgtqvvhbgsdvivhesnkqxmwrqidrvmhlubbryktheyentmrobdeyqcrgluaiihveix";
        ZigZagConversion solution;
        string res = solution.convert(s, 247);
        cout << res << endl;
    }
};
#endif
