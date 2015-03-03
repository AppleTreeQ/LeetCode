//
//  WordBreakII.h
//  LeetCode
//
//  Created by ipuser on 2015/03/02.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 
 Return all such possible sentences.
 
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 
 A solution is ["cats and dog", "cat sand dog"].
 */
#ifndef LeetCode_WordBreakII_h
#define LeetCode_WordBreakII_h
class WordBreakII {
private:
    vector<string> res;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0)
            return res;
        helper(s, dict, "", 0);
        return res;
    }
    void helper(string s, unordered_set<string> &dict, string subs, int start) {
        if (start == s.size()) {
            res.push_back(subs);
            return;
        }
        for (int i = start; i < s.size(); i ++) {
            string str = s.substr(start, i - start + 1);
            if (dict.find(str) != dict.end()) {
                if(subs.size() == 0)
                    subs = str;
                else
                    subs += " " + str;
                helper(s, dict, subs, i + 1);
            }
        }
        return;
    }
};
class WordBreakIITest {
public:
    void test() {
        WordBreakII s;
        string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        unordered_set<string> dict;
        string sss[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        for (int i = 0; i < 10; i ++) {
            dict.insert(sss[i]);
        }
        vector<string> res = s.wordBreak(str, dict);
        cout << res.size() << endl;
    }
};
#endif
