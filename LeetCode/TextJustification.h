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
        vector temp, res;
        int sum = 0;
        for (int i = 0; i < words.size(); i ++) {
            if ((sum + words[i]) < L) {
                temp.push_back(words[i]);
                sum += words[i].size() + 1;
                continue;
            }
            res.push_back(helper(temp));
            temp.clear();
            sum = 0;
        }
    }
    string helper(vector<string> &vect){
        
    }
};
class TextJustificationTest {
public:
    void test() {
        
    }
};
#endif
