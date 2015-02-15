//
//  InterleavingString.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
 */
#ifndef LeetCode_InterleavingString_h
#define LeetCode_InterleavingString_h
class InterleavingString {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<int> stack;
        if (s3.size() != (s1.size() + s2.size())) {
            return false;
        }
        int p1 = 0, p2 = 0, p3 = 0;
        for (; p3 < s3.size(); p3 ++) {
            if (s3[p3] == s1[p1] && s3[p3] == s2[p2]) {
                stack.push_back(p1);
                stack.push_back(p2);
                stack.push_back(p3);
                p1 ++;
            } else if (s3[p3] == s1[p1]) {
                p1 ++;
            } else if (s3[p3] == s2[p2]) {
                p2 ++;
            } else {
                if (stack.size() == 0) {
                    break;
                } else {
                    p3 = stack.back();
                    stack.pop_back();
                    p2 = stack.back() + 1;
                    stack.pop_back();
                    p1 = stack.back();
                    stack.pop_back();
                }
            }
        }
        if(p3 != s3.size())
            return false;
        else
            return true;
    }
};
class InterleavingStringTest {
public:
    void test() {
        InterleavingString s;
        string s1 = "aaaa", s2 = "aaa", s3 = "aaaaaaa";
        s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
        s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
        s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
        cout << s.isInterleave(s1,s2,s3) << endl;
    }
};
#endif
