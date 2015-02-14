//
//  DecodeWays.h
//  LeetCode
//
//  Created by ipuser on 2015/02/12.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
 */
#ifndef LeetCode_DecodeWays_h
#define LeetCode_DecodeWays_h
class DecodeWays {
public:
    int numDecodings(string s) {
        if (s == "") {
            return 0;
        }
        int len = s.size();
        int num[len + 1];
        memset(num, 0, sizeof(int) * (len + 1));
        if (getInt(s[0]) == 0) {
            num[0] = 0;
            num[1] = 0;
        } else {
            num[0] = 1;
            num[1] = 1;
        }
        for (int i = 2; i <= len; i ++) {
            int a = 0;
            a = getInt(s[i - 2])*10 + getInt(s[i-1]);
            if (a == 0) {
                num[i] = 0;
            }
            if ((a >0 && a < 10) || (a > 26)) {
                if (a%10 == 0) {
                    num[i] = 0;
                } else
                    num[i] = num[i - 1];
            }
            if (a >= 10 && a <= 26) {
                if (a == 10 || a == 20) {
                    num[i] = num[i - 2];
                } else
                    num[i] = num[i - 1] + num[i - 2];
            }
        }
        return num[len];
    }
    int getInt(char c) {
        return c - '0';
    }
};
class DecodeWaysTest {
public:
    void test() {
        string str = "230";
        DecodeWays s;
        cout << s.numDecodings(str) << endl;
    }
};

#endif
