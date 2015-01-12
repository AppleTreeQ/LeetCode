//
//  CombinationSumII.h
//  LeetCode
//
//  Created by ipuser on 2015/01/12.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_CombinationSumII_h
#define LeetCode_CombinationSumII_h
class CombinationSumII {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return getCombinationSum(candidates, target, 0);
    }
    vector<vector<int> > getCombinationSum(vector<int> &candidates, int target, int start) {
        vector<vector<int> >  res;
        if (target <= 0)
            return res;
        for(int i = start; i < candidates.size(); i ++) {
            if (target == candidates[i]){
                vector<int> elem;
                elem.push_back(candidates[i]);
                res.push_back(elem);
                break;
            }
            if (target > candidates[i]) {
                vector<vector<int> > new_ = getCombinationSum(candidates, target - candidates[i], i + 1);
                for (int j = 0; j < new_.size(); j++) {
                    vector<int> elem = new_[j];
                    elem.push_back(candidates[i]);
                    res.push_back(elem);
                }
            }
            if (target < candidates[i]) {
                break;
            }
        }
        return res;
    }
};
class CombinationSumIITest {
public:
    void test() {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(10);
        a.push_back(6);
        a.push_back(7);
        a.push_back(1);
        a.push_back(5);
        CombinationSumII solution;
        vector<vector<int> >  res = solution.combinationSum(a, 8);
        for (int i = 0; i < res.size(); i ++) {
            vector<int> elem = res[i];
            for (int j = 0; j < elem.size(); j ++) {
                cout << elem[j] << " ";
            }
            cout << endl;
        }
        return;
    }
};
#endif
