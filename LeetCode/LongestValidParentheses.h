//
//  LongestValidParentheses.h
//  LeetCode
//
//  Created by ipuser on 2015/01/05.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
#ifndef LeetCode_LongestValidParentheses_h
#define LeetCode_LongestValidParentheses_h
struct CharAndIndex {
    char cha;
    int index;
};
class LongestValidParentheses {
public:
    int longestValidParentheses(string s) {
        vector<CharAndIndex> stack;
        int length = s.length(), count = 0;
        if (length <= 1)
            return 0;
        for (int pos = 0; pos < length; pos ++) {
            switch (s[pos]) {
                case '(':
                    CharAndIndex cai;
                    cai.cha = '(', cai.index = pos;
                    stack.push_back(cai);
                    break;
                case ')':
                    //CharAndIndex c = stack.back();
                    if (stack.size() > 0 && stack.back().cha == '(')
                        stack.pop_back();
                    else {
                        CharAndIndex cai;
                        cai.cha = ')', cai.index = pos;
                        stack.push_back(cai);
                    }
                    break;
//                default:
//                    break;
            }
        }
        if (stack.size() == 0)
            return length;
        int lastIndex = -1;
        for (int i = 0; i < stack.size(); i ++) {
            CharAndIndex cai = stack[i];
            int pos = cai.index;
            if ((pos - lastIndex - 1) > count) {
                count = pos - lastIndex - 1;
            }
            lastIndex = pos;
        }
        cout << length << endl;
        count = (length-lastIndex-1)>count ? (length-lastIndex-1) : count;
        return count;
    }
};
class LongestValidParenthesesTest {
public:
    void test() {
        LongestValidParentheses solution;
        string s = ")(";
        int c = solution.longestValidParentheses(s);
        cout << c << endl;
    }
};
#endif
