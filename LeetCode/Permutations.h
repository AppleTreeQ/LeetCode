//
//  Permutations.h
//  LeetCode
//
//  Created by ipuser on 2015/01/19.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
#ifndef LeetCode_Permutations_h
#define LeetCode_Permutations_h
class Permutations {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res, tempres;
        if (num.size() < 1)
            return tempres;
        if (num.size() < 2) {
            tempres.push_back(num);
            return tempres;
        }
        int temp, i;
        sort(num.begin(), num.end());
        for (i = 0; i < num.size(); i ++) {
            temp = num[i];
            num.erase(num.begin() + i);
            tempres = permute(num);
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
class PermutationsTest {
public:
    void test() {
        Permutations solution;
        vector<int> s;
        s.push_back(1);
        s.push_back(2);
        s.push_back(3);
        vector<vector<int> > res = solution.permute(s);
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
