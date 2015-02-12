//
//  ScrambleString.h
//  LeetCode
//
//  Created by ipuser on 2015/02/11.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_ScrambleString_h
#define LeetCode_ScrambleString_h
class ScrambleString {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) {
            return false;
        }
        for (int i = 1; i < s1.size(); i ++) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            //
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                return true;
            }
            s21 = s2.substr(s2.size() - i);
            s22 = s2.substr(0, s2.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                return true;
            }
        }
        return false;
    }
};
class ScrambleStringTest {
public:
    void test() {
        ScrambleString s;
        bool a = s.isScramble("abc", "cba");
        cout << a << endl;
    }
};
#endif
