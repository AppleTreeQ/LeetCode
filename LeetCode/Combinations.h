//
//  Combinations.h
//  LeetCode
//
//  Created by ipuser on 2015/02/04.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_Combinations_h
#define LeetCode_Combinations_h
class Combinations {
private:
    vector<vector<int> > vv;
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        if (k < 1 || n < k)
            return res;
        vector<int> temp;
        helper(temp, 1, n, k);
        return vv;
    }
    void helper(vector<int> &temp, int start, int n, int k) {
        if (k < 1) {
            vv.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i ++) {
            temp.push_back(i);
            helper(temp, i + 1, n, k - 1);
            temp.pop_back();
        }
    }
};
class CombinationsTest {
public:
    void test() {
        Combinations s;
        vector<vector<int> > res = s.combine(4, 2);
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
