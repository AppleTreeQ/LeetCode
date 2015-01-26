//
//  GenerateParentheses.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 qzhai. All rights reserved.
//

#ifndef LeetCode_GenerateParentheses_h
#define LeetCode_GenerateParentheses_h
class GenerateParentheses {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0) {
            generator(result, "", 0, 0, n);
        }
        return result;
    }
    
    void generator(vector<string> &result, string s, int l, int r, int n) {
        if (l == n) {
            result.push_back(s.append(n - r, ')'));
            return;
        }
        generator(result, s + "(", l + 1, r, n);
        if (l > r) {
            generator(result, s + ")", l , r + 1, n);
        }
    }

};
class GenerateParenthesesTest {
public:
    void test() {
        GenerateParentheses solution;
        vector<string> re = solution.generateParenthesis(6);
        cout << re.size() <<endl;
        for (int j = 0; j < re.size(); j ++) {
            cout << re[j] << endl;
        }
    }
};

#endif
