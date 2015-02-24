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
        int length = ladderLength(start, end, dict);
        if (length == 0)
            return res;
        if (length == 2) {
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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() != end.size())
            return 0;
        if (start == end)
            return 2;
        queue<string> ques;
        ques.push(start);
        int steps = 1;
        while (!ques.empty()) {
            int len = ques.size();
            for(int m = 0; m < len; m ++) {
                string s = ques.front();
                ques.pop();
                for (int i = 0; i < s.size(); i ++) {
                    for (int j = 0; j < 26; j ++) {
                        string temp = s;
                        temp[i] = 'a' + j;
                        if (temp == s)
                            continue;
                        if (temp == end)
                            return steps + 1;
                        if (dict.find(temp) != dict.end()) {
                            ques.push(temp);
                        }
                    }
                }
            }
            steps ++;
        }
        return 0;
    }
};
class WordLadderIITest {
public:
    void test() {
        
    }
};
#endif
