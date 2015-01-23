//
//  LengthOfLastWord.h
//  LeetCode
//
//  Created by ipuser on 2015/01/22.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 */
#ifndef LeetCode_LengthOfLastWord_h
#define LeetCode_LengthOfLastWord_h
class LengthOfLastWord {
public:
    int lengthOfLastWord(const char *s) {
        int curlen = 0;
        while (*s != '\0') {
            if (*s == ' ') {
                if (*(s+1) == ' ' || *(s+1) == '\0') {
                    s++;
                    continue;
                }
                curlen = 0;
            } else
                curlen ++;
            s ++;
        }
        return curlen;
    }
};
class LengthOfLastWordTest {
public:
    void test() {
        LengthOfLastWord s;
        char *a = "hello world  ";
        cout << s.lengthOfLastWord(a) << endl;
    }
};
#endif
