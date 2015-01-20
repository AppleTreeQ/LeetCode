//
//  Anagrams.h
//  LeetCode
//
//  Created by ipuser on 2015/01/20.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an array of strings, return all groups of strings that are anagrams.
 Note: All inputs will be in lower-case.
 */
#ifndef LeetCode_Anagrams_h
#define LeetCode_Anagrams_h
#include <unordered_map>
class Anagrams {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, vector<string> > ana;
        for (int i = 0; i < strs.size(); i ++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            ana[str].push_back(strs[i]);
        }
        for (auto i = ana.begin(); i != ana.end(); i ++) {
            vector<string> v = i->second;
            if (v.size() > 1)
                res.insert(res.end(), v.begin(), v.end());
        }
        return res;
    }
};
class AnagramsTest {
public:
    void test() {
        Anagrams s;
        vector<string> v, res;
        v.push_back("slient");
        v.push_back("listen");
        v.push_back("mary");
        v.push_back("army");
        v.push_back("aabb");
        res = s.anagrams(v);
        for (int i = 0; i < res.size(); i ++) {
            cout << res[i] << ", ";
        }
        cout << endl;
    }
};
#endif
