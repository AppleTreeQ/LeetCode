//
//  TextJustification.h
//  LeetCode
//
//  Created by ipuser on 2015/02/02.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_TextJustification_h
#define LeetCode_TextJustification_h
class TextJustification {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if (L < 1)
            return words;
        vector<string> temp, res;
        int sum = 0;
        for (int i = 0; i < words.size(); i ++) {
            if ((sum + words[i].length()) < L) {
                temp.push_back(words[i]);
                sum += words[i].length() + 1;
                continue;
            }
            res.push_back(helper(temp, sum - 1, L));
            temp.clear();
            sum = 0;
            i --;
        }
        if (temp.size() > 0)
            res.push_back(helper2(temp, L));
        return res;
    }
    string helper(vector<string> &vect, int len, int L){
        if (vect.size() == 1) {
            string s = string(L-len, ' ');
            return vect[0]+ s;
        }
        int a = (L - len)/(vect.size() - 1), b = (L - len)%(vect.size() - 1);
        string res;
        for (int i = 0; i < vect.size(); i ++) {
            string s = string(a + 1, ' ');
            res += vect[i] + s;
            if (i < b) {
                res += " ";
            }
        }
        return res;
    }
    string helper2(vector<string> &vect, int L){
        string res;
        int len = 0;
        for (int i = 0; i < vect.size(); i ++) {
            res += vect[i];
            len += vect[i].size();
        }
        string s = string(L - len, ' ');
        return res + s;
    }
    string getStr(int l) {
        string s;
        for (int i = 0; i < l; i ++) {
            s += " ";
        }
        return s;
    }
};
class TextJustificationTest {
public:
    void test() {
        TextJustification s;
        string str[7] = {"This", "is", "an", "example", "of", "text", "justification."};
        vector<string> vec;
        for (int i = 0; i < 7; i ++) {
            vec.push_back(str[i]);
        }
        vector<string> res = s.fullJustify(vec, 16);
        for (int i = 0; i < res.size(); i ++) {
            cout << res[i] << endl;
        }
    }
};
#endif
