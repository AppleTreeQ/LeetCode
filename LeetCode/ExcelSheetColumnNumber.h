//
//  ExcelSheetColumnNumber.h
//  LeetCode
//
//  Created by ipuser on 2015/01/12.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_ExcelSheetColumnNumber_h
#define LeetCode_ExcelSheetColumnNumber_h
/*
 Related to question Excel Sheet Column Title
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 For example:
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 */
class ExcelSheetColumnNumber {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i ++) {
            int k = s[i] - 'A' + 1;
            if (k <= 0 || k > 26)
                return 0;
            res = res * 26 + k;
        }
        return res;
    }
};
class ExcelSheetColumnNumberTest {
public:
    void test() {
        ExcelSheetColumnNumber solution;
        int res = solution.titleToNumber("AB");
        cout << res << endl;
    }
};
#endif
