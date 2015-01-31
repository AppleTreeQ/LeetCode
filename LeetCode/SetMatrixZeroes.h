//
//  SetMatrixZeroes.h
//  LeetCode
//
//  Created by ipuser on 2015/01/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */
#ifndef LeetCode_SetMatrixZeroes_h
#define LeetCode_SetMatrixZeroes_h
class SetMatrixZeroes {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return;
        int m = matrix.size(), n = matrix[0].size();
        int *flag = new int[m + n];
        memset(flag, 0, (m + n) * sizeof(int));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if(matrix[i][j] == 0) {
                    flag[i] = 1;
                    flag[j + m] = 1;
                }
            }
        }
        for (int i = 0; i < (m + n); i ++) {
            if (flag[i]) {
                if (i < m) {
                    for (int j = 0; j < n; j ++) {
                        matrix[i][j] = 0;
                    }
                } else {
                    for (int j = 0; j < m; j ++) {
                        matrix[j][i - m] = 0;
                    }
                }
            }
        }
        delete [] flag;
        return;
    }
};
class SetMatrixZeroesTest {
public:
    void test() {
        vector<vector<int> > matrix;
        vector<int> he(1, 1);
        matrix.push_back(he);
        SetMatrixZeroes s;
        s.setZeroes(matrix);
        for (int i = 0; i < 1; i ++) {
            for (int j = 0; j < 1; j ++) {
                cout << matrix[i][j] << ", ";
            }
            cout << endl;
        }
    }
};
#endif
