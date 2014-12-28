//
//  LongestCommonPrefix.h
//  LeetCode
//
//  Created by ipuser on 2014/12/28.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_LongestCommonPrefix_h
#define LeetCode_LongestCommonPrefix_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs.size(), index = 0;
        if (size == 0)
            return "";
        if (size == 1)
            return strs[0];
        bool common = true;
        char c;
        string result;
        while (common) {
            if ((c = strs[0][index]) != '\0') {
                for (int i = 1; i < size; i ++) {
                    if ( strs[i][index] == '\0' || c != strs[i][index]) {
                        common = false;
                        break;
                    }
                }
                if( common ) {
                    result += c;
                    index ++;
                }
            } else {
                break;
            }
        }
        return result;
    }
};

class LongestCommonPrefixTest {
public:
    void test() {
        vector<string> v;
        v.push_back("suma");
        v.push_back("sumb");
        LongestCommonPrefix solution;
        cout << solution.longestCommonPrefix(v) << endl;
    }
};
#endif
