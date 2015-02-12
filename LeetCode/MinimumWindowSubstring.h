//
//  MinimumWindowSubstring.h
//  LeetCode
//
//  Created by ipuser on 2015/01/31.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
 Note:
 If there is no such window in S that covers all characters in T, return the emtpy string "".
 
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
#ifndef LeetCode_MinimumWindowSubstring_h
#define LeetCode_MinimumWindowSubstring_h
class MinimumWindowSubstring {
public:
    string minWindow(string S, string T) {
        vector<int> sample;
        unordered_map<char, int> map;
        for (int i = 0; i < T.size(); i ++) {
            map[T[i]] ++;
        }
        for (int i = 0; i < S.size(); i ++) {
            if (map[S[i]] > 0)
                sample.push_back(i);
        }
        if (sample.size() < T.size()) {
            return "";
        }
        int start = 0, end = 0, window = S.size(), start_bak = -1;
        while (start <= sample.size()-T.size()) {
            if (end < sample.size()) {
                map[S[sample[end]]] --;
            }
            if (isZero(map)) {
                int e = end < sample.size() ? end : sample.size() - 1;
                int minus = sample[e] - sample[start] + 1;
                if (window > minus) {
                    window = minus;
                    start_bak = sample[start];
                }
                map[S[sample[start]]] ++;
                start ++;
            } else if( end >= sample.size()) {
                map[S[sample[start]]] ++;
                start ++;
            }
            end ++;
        }
        if (start_bak == -1)
            return "";
        else
            return S.substr(start_bak, window);
    }
    bool isZero(unordered_map<char, int> &m) {
        for (auto i = m.begin(); i != m.end(); i ++) {
            if (i->second > 0) {
                return false;
            }
        }
        return true;
    }
};
class MinimumWindowSubstringTest {
public:
    void test() {
        MinimumWindowSubstring s;
        string s1 = "A", s2 = "A";
        cout << s.minWindow(s1, s2) << endl;
    }
};
#endif
