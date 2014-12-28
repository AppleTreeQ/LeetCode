//
//  ValidParentheses.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_ValidParentheses_h
#define LeetCode_ValidParentheses_h
#include <iostream>
using namespace std;

class ValidParentheses {
public:
    bool isValid(string s) {
        vector<char> stac;
        char c;
        if ( s.size() == 1 )
            return false;
        for ( int i = 0; i < s.size(); i ++ ) {
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
                stac.push_back(s[i]);
            }
            if ( s[i] == ')' || s[i] == ']' || s[i] == '}' ) {
                if (stac.empty())
                    return false;
                c = stac.back();
                stac.pop_back();
                if ( s[i] == ')' && c != '(' )
                    return false;
                if ( s[i] == ']' && c != '[' )
                    return false;
                if ( s[i] == '}' && c != '{' )
                    return false;
            }
        }
        if ( stac.empty() )
            return true;
        else
            return false;
    }
};
class ValidParenthesesTest {
public:
    void test() {
        string s = ")}{({))[{{[}";
        ValidParentheses solution;
        cout << solution.isValid(s) << endl;
    }
};

#endif
