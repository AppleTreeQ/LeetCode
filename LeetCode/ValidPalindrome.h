//
//  ValidPalindrome.h
//  LeetCode
//
//  Created by ipuser on 2015/02/20.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_ValidPalindrome_h
#define LeetCode_ValidPalindrome_h
class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        if (s.size() < 1)
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            int c1 = charValue(s[i]);
            int c2 = charValue(s[j]);
            if (c1 < 0) {
                i ++;
                continue;
            }
            if (c2 < 0) {
                j --;
                continue;
            }
            if (c1 == c2) {
                i ++;
                j --;
                continue;
            }
            if (c1 != c2) {
                return false;
            }
        }
        return true;
    }
    int charValue(char c) {
        if ((c - 'a') >=0 && (c - 'a') < 26)
            return (c - 'a');
        else if ((c - 'A') >=0 && (c - 'A') < 26)
            return (c - 'A');
        else if ((c - '0') >=0 && (c - '0') < 10)
            return (c - '0') + 26;
        else
            return -1;
    }
};
class ValidPalindromeTest {
public:
    void test() {
        
    }
};
#endif
