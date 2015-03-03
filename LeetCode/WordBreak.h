//
//  WordBreak.h
//  LeetCode
//
//  Created by ipuser on 2015/03/02.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".
 */
#ifndef LeetCode_WordBreak_h
#define LeetCode_WordBreak_h
class WordBreak {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0)
            return true;
        vector<int> indexs;
        indexs.push_back(-1);
        for (int i = 0; i < s.size(); i ++) {
            for (int j = indexs.size() - 1; j >= 0; j --) {
                string subs = s.substr(indexs[j] + 1, i - indexs[j]);
                if (dict.find(subs) != dict.end()) {
                    indexs.push_back(i);
                    break;
                }
            }
        }
        if (indexs.back() == s.size() - 1) {
            return true;
        }
        return false;
    }
};
class WordBreakTest {
public:
    void test() {
        
    }
};
#endif
