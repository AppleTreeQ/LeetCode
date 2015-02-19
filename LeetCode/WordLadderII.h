//
//  WordLadderII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/20.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_WordLadderII_h
#define LeetCode_WordLadderII_h
class WordLadderII {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > res;
        if (start.size() != end.size())
            return res;
        if (start == end) {
            vector<string> v;
            v.push_back(start);
            v.push_back(end);
            res.push_back(v);
            return res;
        }
        queue<string> ques;
        ques.push(start);
        int steps = 1;
        while (!ques.empty()) {
            int len = ques.size();
            string s = ques.front();
            ques.pop();
            for (int m = 0; m < len; m ++) {
                
            }
        }
    }
};
class WordLadderIITest {
public:
    void test() {
        
    }
};
#endif
