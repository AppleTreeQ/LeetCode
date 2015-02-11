//
//  SubsetsII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/11.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SubsetsII_h
#define LeetCode_SubsetsII_h
class SubsetsII {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> temp;
        vector<vector<int> > res;
        res.push_back(temp);
        if (S.size() < 1) {
            return res;
        }
        sort(S.begin(), S.end());
        vector<vector<int> > res2 = helper(res, S, 1);
        res.insert(res.end(), res2.begin(), res2.end());
        return res;
    }
    vector<vector<int> > helper(vector<vector<int> > vv, vector<int> &S, int size) {
        vector<vector<int> > temp;
        if (size > S.size()) {
            return temp;
        }
        for (int i = 0; i < vv.size(); i ++) {
            vector<int> v = vv[i];
            int start = getStartIndex(v, S);
            for (int j = start; j < S.size(); j ++) {
                if (j < (S.size() - 1) && S[j] == S[j + 1]) {
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
    int getStartIndex(vector<int> &v, vector<int> &S) {
        if (v.size() < 1) {
            return 0;
        }
        int i = 0, j = 0;
        while (i < v.size()) {
            if (v[i] == S[j])
                i ++;
            j ++;
        }
        return j;
    }
};
class SubsetsIITest {
public:
    void test() {
        int a[] = {1,2,2,2, 3};
        vector<int> v;
        for (int i = 0; i < sizeof(a)/sizeof(int); i ++) {
            v.push_back(a[i]);
        }
        SubsetsII s;
        vector<vector<int> > res = s.subsetsWithDup(v);
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
