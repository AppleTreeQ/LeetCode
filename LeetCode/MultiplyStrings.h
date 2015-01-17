//
//  MultiplyStrings.h
//  LeetCode
//
//  Created by ipuser on 2015/01/17.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given two numbers represented as strings, return multiplication of the numbers as a string.
 
 Note: The numbers can be arbitrarily large and are non-negative.
 */
#ifndef LeetCode_MultiplyStrings_h
#define LeetCode_MultiplyStrings_h
class MultiplyStrings {
public:
    string multiply(string num1, string num2) {
        if(num1.length() == 0 || num2.length() == 0)
            return "";
        string res(num1.length() + num2.length() + 1, '0'); // 这个是亮点
        int temp1, temp2, carry = 0, exist, i, j;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for (i =0; i < num1.length(); i++) {
            temp1 = num1[i] - '0';
            for (j = 0; j< num2.length(); j++) {
                temp2 = num2[j] - '0';
                exist = res[i + j] - '0';
                temp2 = temp1 * temp2 + carry + exist;
                res[i + j] = (temp2 % 10 + '0');
                carry = temp2 / 10;
            }
            if (carry > 0) {
                res[i + j] =carry + '0';
                carry = 0;
            }
        }
        int k;
        for (k = res.length() - 1; k >= 0; k --) {
            if (res[k] != '0')
                break;
        }
        if (k < 0) {
            return "0";
        }
        res = res.substr(0, k + 1);
        std::reverse(res.begin(), res.end());
        return res;
    }
};
class MultiplyStringsTest {
public:
    void test() {
        MultiplyStrings solution;
        string res = solution.multiply("0", "0");
        cout << res << endl;
    }
};
#endif
