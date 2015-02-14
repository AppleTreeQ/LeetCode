//
//  RestoreIPAddresses.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 
 For example:
 Given "25525511135",
 
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
#ifndef LeetCode_RestoreIPAddresses_h
#define LeetCode_RestoreIPAddresses_h
class RestoreIPAddresses {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) {
            return res;
        }
        helper(s, 4, "");
        return res;
    }
    void helper(string s, int partNum, string target) {
        if (partNum < 0) {
            return;
        }
        if (s.size() > partNum*3 || s.size() < partNum) {
            return;
        }
        if (partNum == 0) {
            res.push_back(target.substr(1));
            return;
        }
        cout << s << endl;
        for (int i = 1; i < 4 && i <= s.size(); i ++) {
            string temp = s.substr(0, i);
            cout << temp << endl;
            if (validateNum(temp)) {
                helper(s.substr(i), partNum - 1, target + "." + temp);
            }
        }
    }
    bool validateNum(string s) {
        if(s.size()> 1 && s[0] == '0')
            return false;
        int a = s[0] - '0';
        for (int i = 1; i < s.size(); i ++) {
            a = a * 10 + (s[i] - '0');
        }
        if (a <= 255)
            return true;
        else
            return false;
    }
};
class RestoreIPAddressesTest {
public:
    void test() {
        RestoreIPAddresses s;
        string str = "25525511135";
        vector<string> res = s.restoreIpAddresses(str);
        for (int i = 0; i < res.size(); i ++) {
            cout << res[i] << endl;
        }
    }
};
#endif
