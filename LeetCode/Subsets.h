//
//  Subsets.h
//  LeetCode
//
//  Created by ipuser on 2015/02/07.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_Subsets_h
#define LeetCode_Subsets_h
class Subsets {
private:
    vector<vector<int> > res;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> temp;
        res.push_back(temp);
        sort(S.begin(), S.end());
        helper(temp, S, 0);
        //sort(res.begin(), res.end());
        return res;
    }
    void helper(vector<int> temp, vector<int> &S, int start) {
        if (start >= S.size()) {
            return;
        }
        for (int i = start; i < S.size(); i ++) {
            temp.push_back(S[i]);
            res.push_back(temp);
            temp.pop_back();
        }
        for (int i = start; i < S.size(); i ++) {
            temp.push_back(S[i]);
            helper(temp, S, i + 1);
            temp.pop_back();
        }
    }
};

class Subsets2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> temp;
        vector<vector<int> > res;
        res.push_back(temp);
        sort(S.begin(), S.end());
        vector<vector<int> > a = helper(res, S, 1);
        res.insert(res.end(), a.begin(), a.end());
        return res;
    }
    vector<vector<int> > helper(vector<vector<int> > vv, vector<int> &S, int size) {
        vector<vector<int> > temp;
        if (size > S.size()) {
            return temp;
        }
        for (int i = 0; i < vv.size(); i ++) {
            vector<int> v = vv[i];
            for (int j = v.size(); j < S.size(); j ++) {
                if (v.size() > 0 && S[j] <= v.back()) {
                    continue;
                }
                v.push_back(S[j]);
                temp.push_back(v);
                v.pop_back();
            }
        }
        vector<vector<int> > temp2 = helper(temp, S, size + 1);
        temp.insert(temp.end(), temp2.begin(), temp2.end());
        return temp;
    }
};

class SubsetsTest {
public:
    void test() {
        Subsets2 s;
        vector<int > input;
        input.push_back(1);
        input.push_back(2);
        input.push_back(3);
        vector<vector<int> > res = s.subsets(input);
        for (int i = 0; i < res.size(); i ++) {
            vector<int> temp = res[i];
            for (int j = 0; j < temp.size(); j ++) {
                cout << temp[j] << ",";
            }
            cout << endl;
        }
    }
};
#endif
