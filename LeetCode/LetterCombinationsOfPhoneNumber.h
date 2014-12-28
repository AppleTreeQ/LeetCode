//
//  LetterCombinationsOfPhoneNumber.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_LetterCombinationsOfPhoneNumber_h
#define LeetCode_LetterCombinationsOfPhoneNumber_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LetterCombinationsOfPhoneNumber {
public:
    vector<string> letterCombinations(string digits) {
        string p[] = {" ", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> re;
        int index;
        if (digits.length() < 1) {
            re.push_back("");
            return re;
        }
        index = digits[0] - '0';
        vector<string> substring = letterCombinations(digits.substr(1, digits.size()-1));
        if ( index >= 0 && index <= 9 ) {
            for( int i = 0; i < p[index].size(); i ++ ) {
                for ( int j = 0; j < substring.size(); j ++ ) {
                    re.push_back(p[index][i] + substring[j]);
                }
            }
        } else {
            re.push_back(digits);
        }
        return re;
    }
};
class LetterCombinationsOfPhoneNumberTest {
public:
    void test() {
        string s = "247";
        LetterCombinationsOfPhoneNumber solution;
        vector<string> re = solution.letterCombinations(s);
        for (int i = 0; i < re.size(); i ++) {
            cout << re[i] << endl;
        }
    }
};
#endif
