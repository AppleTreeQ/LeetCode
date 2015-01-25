//
//  PlusOne.h
//  LeetCode
//
//  Created by ipuser on 2015/01/25.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 */
#ifndef LeetCode_PlusOne_h
#define LeetCode_PlusOne_h
class PlusOne {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.size() == 0) {
            digits.push_back(1);
            return digits;
        }
        int carry = 0, carry_temp;
        for (int i = digits.size() - 1; i >= 0; i --) {
            if (i == digits.size() - 1) {
                carry = 1;
            }
            carry_temp = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + carry) % 10;
            carry = carry_temp;
            if (carry == 0)
                break;
        }
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
class PlusOneTest {
public:
    void test() {
        vector<int> v;
        v.push_back(0);
        PlusOne s;
        vector<int> res = s.plusOne(v);
        for (int i = 0; i < res.size(); i ++) {
            cout << res[i];
        }
        cout << endl;
    }
};
#endif
