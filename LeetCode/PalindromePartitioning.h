//
//  PalindromePartitioning.h
//  LeetCode
//
//  Created by ipuser on 2015/02/25.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 */
#ifndef LeetCode_PalindromePartitioning_h
#define LeetCode_PalindromePartitioning_h
class PalindromePartitioning {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() == 0)
            return res;
        vector<string> v;
        helper(res, v, s);
        return res;
    }
    void helper(vector<vector<string>> &res, vector<string> vv, string s) {
        if (s.size() == 0) {
            res.push_back(vv);
            return;
        }
        for (int i = 0; i < s.size(); i ++) {
            string subs = s.substr(0, i+1);
            if (checkPal(subs)) {
                vv.push_back(subs);
                helper(res, vv, s.substr(i + 1));
                vv.pop_back();
            }
        }
    }
    bool checkPal(string s){
        if (s.size() < 2)
            return true;
        int size = s.size();
        for (int i = 0; i < size / 2; i ++) {
            if(s[i] != s[size - i -1])
                return false;
        }
        return true;
    }
};
class PalindromePartitioningTest {
public:
    void test() {
        PalindromePartitioning s;
        vector<vector<string>> res = s.partition("aaa");
        for (int i = 0; i < res.size(); i ++) {
            vector<string> v = res[i];
            for (int j = 0; j < v.size(); j ++) {
                cout << v[j] << ", ";
            }
            cout << endl;
        }
    }
};
#endif
