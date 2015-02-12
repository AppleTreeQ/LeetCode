//
//  DecodeWays.h
//  LeetCode
//
//  Created by ipuser on 2015/02/12.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_DecodeWays_h
#define LeetCode_DecodeWays_h
class DecodeWays {
private:
    int num;
public:
    int numDecodings(string s) {
        num = 0;
        if (s == NULL || s == "") {
            return num;
        }
        helper(s, 0);
        return num;
    }
    void helper(string &s, int start) {
        if (start > s.size()) {
            return;
        }
        if (start == s.size()) {
            num ++;
        }
        int a = s[start] - '0';
        if (a == 1) {
            <#statements#>
        }
    }
};
class DecodeWaysTest {
public:
    void test() {
        
    }
};

#endif
