//
//  WordLadder.h
//  LeetCode
//
//  Created by ipuser on 2015/02/20.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_WordLadder_h
#define LeetCode_WordLadder_h
#include <unordered_set>
class WordLadder {
public:
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
class WordLadderTest {
public:
    void test() {
        WordLadder s;
        string start = "hit", end = "cog";
        unordered_set<string> dict;
        dict.insert("hot");
        dict.insert("dot");
        dict.insert("dog");
        dict.insert("lot");
        dict.insert("log");
        cout << s.ladderLength(start, end, dict) << endl;
    }
};
#endif
