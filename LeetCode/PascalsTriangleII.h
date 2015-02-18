//
//  PascalsTriangleII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/18.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an index k, return the kth row of the Pascal's triangle.
 
 For example, given k = 3,
 Return [1,3,3,1].
 
 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 */
#ifndef LeetCode_PascalsTriangleII_h
#define LeetCode_PascalsTriangleII_h
class PascalsTriangleII {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex < 0)
            return res;
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i <= rowIndex; i ++) {
            res = v;
            v.clear();
            v.push_back(1);
            for (int j = 1; j < i; j ++) {
                v.push_back(res[j] + res[j-1]);
            }
            v.push_back(1);
        }
        res = v;
        return res;
    }
};
class PascalsTriangleIITest {
public:
    void test() {
        PascalsTriangleII s;
        vector<int> v = s.getRow(3);
        for (int j = 0; j < v.size(); j ++) {
            cout << v[j] << ", ";
        }
        cout << endl;
    }
};

#endif
