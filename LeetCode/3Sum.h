//
//  3Sum.h
//  LeetCode
//
//  Created by ipuser on 2014/12/28.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode__Sum_h
#define LeetCode__Sum_h
#include <iostream>
#include <vector>
using namespace std;

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<int> num_bak = new vector<int>();
        int lastInt = num[0];
        num_bak.push_back(lastInt);
        for (int i = 1; i < num.size(); i ++) {
            if (num[i] != lastInt) {
                lastInt =  num[i];
                num_bak.push_back(lastInt);
            }
        }
        if (num_bak.size() < 3)
            return;
        
    }
};
class ThreeSumTest {
public:
    void test() {
        
    }
};
#endif
