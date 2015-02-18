//
//  PascalsTriangle.h
//  LeetCode
//
//  Created by ipuser on 2015/02/18.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */
#ifndef LeetCode_PascalsTriangle_h
#define LeetCode_PascalsTriangle_h
class PascalsTriangle {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1)
            return res;
        vector<int> v, prev;
        v.push_back(1);
        res.push_back(v);
        for (int i = 1; i < numRows; i ++) {
            prev = v;
            v.clear();
            v.push_back(1);
            for (int j = 1; j < i; j ++) {
                v.push_back(prev[j] + prev[j-1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
    }
};
class PascalsTriangleTest {
public:
    void test() {
        PascalsTriangle s;
        vector<vector<int> > res = s.generate(5);
        for (int i = 0; i < res.size(); i ++) {
            vector<int> v = res[i];
            for (int j = 0; j < v.size(); j ++) {
                cout << v[j] << ", ";
            }
            cout << endl;
        }
    }
};
#endif
