//
//  LongestPalindromicSubstring .h
//  LeetCode
//
//  Created by ipuser on 2014/12/21.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

/*
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#ifndef LeetCode_LongestPalindromicSubstring__h
#define LeetCode_LongestPalindromicSubstring__h
#include <iostream>
#include <string>
using namespace std;
//O(n*n)
class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s) {
        if ( s.length() < 1 )
            return s;
        int maxLen = 0;
        string substring;
        int flag1, flag2;
        for ( int index = 0; index < s.length(); index ++ ) {
            flag1 = 0;
            flag2 = 0;
            int searchLen = index < ( s.length() - index ) ? index : ( s.length() - index );
            for ( int i = 0; i <=searchLen; i ++ ) {
                if (s[index - i] == s[index + i]) {
                    if (( 2 * i + 1 ) > maxLen) {
                        if ( flag1 == 0 ) {
                            maxLen = 2 * i + 1;
                            substring = s.substr( index - i, 2 * i + 1 );
                        }
                    }
                } else {
                    flag1 = 1;
                }
                if ( s[index - i] == s[index + 1 + i]) {
                    if (( 2 * i + 2) > maxLen) {
                        if (flag2 == 0) {
                            maxLen = 2 * i + 2;
                            substring = s.substr( index - i, 2 * i + 2);
                        }
                    }
                } else {
                    flag2 = 1;
                }
            }
        }
        return substring;
    }
};
// O(n)

class LongestPalindromicSubstringTest {
public:
    void test() {
        string s = "abbbbb";
        LongestPalindromicSubstring solution;
        string result = solution.longestPalindrome(s);
        cout << result << endl;
        return;
    }
};
#endif
