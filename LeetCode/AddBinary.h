//
//  AddBinary.h
//  LeetCode
//
//  Created by ipuser on 2015/01/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".
 */
#ifndef LeetCode_AddBinary_h
#define LeetCode_AddBinary_h
class AddBinary {
public:
    string addBinary(string a, string b) {
        if (a == "" || b == "") {
            return (a + b);
        }
        string shortStr, longStr;
        if (a.size() < b.size()) {
            shortStr = a;
            longStr = b;
        } else {
            shortStr = b;
            longStr = a;
        }
        int carry = 0, temp_carry = 0, diff = longStr.size() - shortStr.size(), digit1, digit2;
        for (int i = longStr.size() - 1; i >= 0; i --) {
            if (i >= diff)
                digit1 = shortStr[i - diff] - '0';
            else
                digit1 = 0;
            digit2 = longStr[i] - '0';
            temp_carry = (digit1 + digit2 + carry) / 2;
            longStr[i] = '0' + (digit1 + digit2 + carry) % 2;
            carry = temp_carry;
        }
        if (carry != 0) {
            longStr = "1" + longStr;
        }
        return longStr;
    }
};
class AddBinaryTest {
public:
    void test() {
        AddBinary s;
        string res = s.addBinary("1010", "11");
        cout << res << endl;
    }
};
#endif
