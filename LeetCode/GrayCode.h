//
//  GrayCode.h
//  LeetCode
//
//  Created by ipuser on 2015/02/11.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 */
#ifndef LeetCode_GrayCode_h
#define LeetCode_GrayCode_h
class GrayCode {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
            return res;
        }
        res.push_back(0);
        res.push_back(1);
        int plus = 1;
        for (int i = 1; i < n; i ++) {
            int size = res.size();
            for (int pos = size / 2; pos < size; pos ++) {
                int a = (res[pos] << 1) + plus;
                res.push_back(a);
                plus = (plus + 1) % 2;
                a = (res[pos] << 1) + plus;
                res.push_back(a);
            }
        }
        return res;
    }
};
class GrayCodeTest {
public:
    void test() {
        GrayCode s;
        vector<int> res = s.grayCode(3);
        for (int i = 0 ; i < res.size(); i ++) {
            cout << res[i] << ",";
        }
        cout << endl;
    }
};
#endif
