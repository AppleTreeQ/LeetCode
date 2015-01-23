//
//  SpiralMatrixII.h
//  LeetCode
//
//  Created by ipuser on 2015/01/22.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 
 For example,
 Given n = 3,
 
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 */
#ifndef LeetCode_SpiralMatrixII_h
#define LeetCode_SpiralMatrixII_h
class SpiralMatrixII {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int> > res(n, row);
        helper(res, 1, 0, 0, n);
        return res;
    }
    void helper(vector<vector<int> > &res, int start, int xpos, int ypos, int n) {
        if (n == 0) {
            return;
        }
        if (n == 1) {
            res[ypos][xpos] = start;
            return;
        }
        //  row above
        for (int i = xpos; i < xpos + n; i ++) {
            res[ypos][i] = start;
            start ++;
        }
        // right column
        for (int i = ypos + 1; i < ypos + n; i ++) {
            res[i][xpos + n - 1] = start;
            start ++;
        }
        // row below
        for (int i = xpos + n - 2; i >= xpos; i --) {
            res[ypos + n -1][i] = start;
            start ++;
        }
        // left column
        for (int i = ypos + n - 2; i > ypos; i --) {
            res[i][xpos] = start;
            start ++;
        }
        helper(res, start, xpos + 1, ypos + 1, n - 2);
        return;
    }
};
class SpiralMatrixIITest {
public:
    void test() {
        SpiralMatrixII s;
        int n = 0;
        vector<vector<int> > res = s.generateMatrix(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << res[i][j] << ", ";
            }
            cout << endl;
        }
    }
};
#endif
