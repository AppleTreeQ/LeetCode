//
//  ImplementstrStr.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_ImplementstrStr_h
#define LeetCode_ImplementstrStr_h


class ImplementstrStr {
public:
    int strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL)
            return -1;
        if (needle[0] == '\0')
            return 0;
        int pos = -1;
        int i = 0, j = 0;
        for (; haystack[i] != '\0'; i ++) {
            if (haystack[i] == needle[j] && needle[j] != '\0') {
                i ++;
                j ++;
                if (pos == -1)
                    pos = i - 1;
            } else {
                if (needle[j] == '\0') {
                    break;
                }
                if (haystack[i] != needle[j]) {
                    i ++;
                    j = 0;
                    pos = -1;
                }
            }
        }
        if (haystack[i] == '\0' && needle[j] != '\0')
            return -1;
        return pos;
    }
};
class ImplementstrStrTest {
public:
    void test() {
        char str[] = "mississippi";
        char sub[] = "issip";
        char *pch = strstr(str, sub);
        cout << *pch << endl;
        ImplementstrStr solution;
        int pos = solution.strStr(str, sub);
        cout << str[pos] << ", " << pos << endl;
    }
};
#endif
