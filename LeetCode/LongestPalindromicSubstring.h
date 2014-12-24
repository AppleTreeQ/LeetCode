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
#include <algorithm>
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
   // 我认为给出的算法有点问题。用这个test，测出的结果不一样。需要研究一下。
    string preProcess(string s) {
        if(s.length() < 1)
            return "^$";
        string ret = "^#";
        for (int i = 0; i < s.length(); i ++) {
            ret += s[i] + "#";
        }
        ret += "$";
        return ret;
    }
    string longestPalindrome2(string s) {
        /*string news = preProcess(s);
        int mx = 0, id = 0;
        int len = news.length();
        int *p = new int[len];
        for (int i = 1; i < news.length(); i ++) {
            if (mx > i) {
                p[i] = min(p[2 * id - i], mx - i);
            } else {
                p[i] = 0;
            }
            for (; news[i + p[i] + 1] == news[i - p[i] - 1]; p[i] ++)
                ;
            if (( i + p[i] ) > mx ) {
                mx = i + p[i];
                id = i;
            }
        }
        int maxLen = 0;
        int centerIndex = 0;
        for ( int i = 1; i < news.length(); i ++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        delete[] p;
        return s.substr((centerIndex - maxLen - 1 ) / 2, maxLen);*/
        string T = preProcess(s);
        int n = T.length();
        int *P = new int[n];
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++) {
            int i_mirror = 2*C-i; // equals to i' = C - (i-C)
            
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
            
            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        
        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        delete[] P;
        
        return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
    }
    
};
// Manacher’s algorithm


class LongestPalindromicSubstringTest {
public:
    void test() {
        string s = "babcbabcbaccba";
        LongestPalindromicSubstring solution;
        string result = solution.longestPalindrome2(s);
        cout << result << endl;
        return;
    }
};
#endif
