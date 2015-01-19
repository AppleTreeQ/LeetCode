//
//  PermutationsII.h
//  LeetCode
//
//  Created by ipuser on 2015/01/19.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 */
#ifndef LeetCode_PermutationsII_h
#define LeetCode_PermutationsII_h
class PermutationsII {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res, tempres;
        if (num.size() < 1)
            return res;
        if (num.size() < 2) {
            res.push_back(num);
            return res;
        }
        sort(num.begin(), num.end());
        int temp;
        for (int i = 0; i < num.size(); i ++) {
            if (i > 0 && num[i - 1] == num[i])
                continue;
            temp = num[i];
            num.erase(num.begin() + i);
            tempres = permuteUnique(num);
            for (int j = 0; j < tempres.size(); j ++) {
                vector<int> v = tempres[j];
                v.push_back(temp);
                res.push_back(v);
            }
            num.push_back(temp);
            sort(num.begin(), num.end());
        }
        return res;
    }
};
class PermutationsIITest {
public:
    void test() {
        PermutationsII solution;
        vector<int> s;
        s.push_back(1);
        s.push_back(1);
        s.push_back(2);
        vector<vector<int> > res = solution.permuteUnique(s);
        for (int i = 0; i < res.size(); i ++) {
            vector<int> temp = res[i];
            for (int j = 0; j < temp.size(); j ++) {
                cout << temp[j] << ", ";
            }
            cout << endl;
        }
    }
};
#endif
