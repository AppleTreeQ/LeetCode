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
        vector<vector<int> >  res;
        if (candidates.size() < 1 || target <= 0) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        for (int i = 0; i < candidates.size(); i ++) {
            int j = i;
            vector<int> *temp = new vector<int>;
            while (true) {
                sum += candidates[j];
                temp->push_back(candidates[j]);
                if (sum == target) {
                    res.push_back(*temp);
                    temp->pop_back();
                    sum -= candidates[j];
                    j ++;
                }
                if (sum > target) {
                    
                }
            }
            
        }
        return res;
    }
};
class CombinationSumTest {
public:
    void test() {
        CombinationSum solution;
        return;
    }
};
#endif
