//
//  CountAndSay.h
//  LeetCode
//
//  Created by ipuser on 2015/01/07.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
 */
#ifndef LeetCode_CountAndSay_h
#define LeetCode_CountAndSay_h
class CountAndSay {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        string res = "1", lastStr = "";
        int count = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < lastStr.length(); j ++) {
                if (lastStr[j] == lastStr[j + 1]) {
                    count ++;
                } else {
                    res += std::to_string(count) + lastStr[j];
                    count = 1;
                    if (lastStr[j + 1] == '\0')
                        break;
                }
            }
            lastStr = res;
            res = "";
        }
        return lastStr;
    }
};
class CountAndSayTest {
public:
    void test() {
        CountAndSay solution;
        string res = solution.countAndSay(9);
        cout << res << endl;
    }
};
#endif
