//
//  PalindromePartitioningII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/26.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_PalindromePartitioningII_h
#define LeetCode_PalindromePartitioningII_h
class PalindromePartitioningII {
public:
    int minCut(string s) {
        vector<vector<string>> res;
        if (s.size() == 0)
            return 0;
        vector<string> v;
        helper(res, v, s);
        int num = res[0].size();
        for (int i = 0; i < res.size(); i ++) {
            num = num < res[i].size() ? num : res[i].size();
            vector<string> v = res[i];
            for (int j = 0; j < v.size(); j ++) {
                cout << v[j] << ", ";
            }
            cout << endl;
        }
        return num - 1;
    }
    void helper(vector<vector<string>> &res, vector<string> vv, string s) {
        if (s.size() == 0) {
            res.push_back(vv);
            return;
        }
        for (int i = 0; i < 0; i --) {
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
class PalindromePartitioningIITest {
public:
    void test() {
        PalindromePartitioningII s;
        cout << s.minCut("aaabaa") << endl;
    }
};
#endif
