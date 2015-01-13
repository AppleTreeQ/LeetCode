//
//  CombinationSum.h
//  LeetCode
//
//  Created by ipuser on 2015/01/07.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 */
#ifndef LeetCode_CombinationSum_h
#define LeetCode_CombinationSum_h
#include <queue>
class CombinationSum {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return getCombinationSum2(candidates, target, candidates.size() - 1);
    }
    vector<vector<int> > getCombinationSum(vector<int> &candidates, int target, int start){
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
                vector<vector<int> > new_ = getCombinationSum(candidates, target - candidates[i], i);
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
    vector<vector<int> > getCombinationSum2(vector<int> &candidates, int target, int start){
        vector<vector<int> >  res;
        if (target <= 0)
            return res;
        for(int i = start; i >= 0; i --) {
            if (target == candidates[i]){
                vector<int> elem;
                elem.push_back(candidates[i]);
                res.push_back(elem);
                continue;
            }
            if (target > candidates[i]) {
                vector<vector<int> > new_ = getCombinationSum2(candidates, target - candidates[i], i);
                for (int j = 0; j < new_.size(); j++) {
                    vector<int> elem = new_[j];
                    elem.push_back(candidates[i]);
                    res.push_back(elem);
                }
            }
        }
        return res;
    }
};
class CombinationSumTest {
public:
    void test() {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(6);
        a.push_back(7);
        CombinationSum solution;
        vector<vector<int> >  res = solution.combinationSum(a, 7);
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
