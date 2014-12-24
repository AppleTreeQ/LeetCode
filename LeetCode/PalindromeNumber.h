//
//  PalindromeNumber.h
//  LeetCode
//
//  Created by ipuser on 2014/12/24.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_PalindromeNumber_h
#define LeetCode_PalindromeNumber_h
#include <iostream>
using namespace std;
class PalindromeNumber {
public:
    bool isPalindrome(int x) {
        int newx = 0;
        int bakx = x;
        if (x < 0) {
            if (x == INT_MIN)
                return false;
            else
                x = -x;
        }
        while ( x > 0) {
            int mod = x % 10;
            if (INT_MAX / 10 < newx)
                return false;
            if ((INT_MAX - 10 * newx) < mod)
                return false;
            newx = newx * 10 + mod;
            x = x / 10;
        }
        if (newx == bakx)
            return true;
        else
            return false;
    }
};
class PalindromeNumberTest {
public:
    void test() {
        int i = 1;
        PalindromeNumber solution;
        cout << solution.isPalindrome(i) << endl;
    }
};

#endif
