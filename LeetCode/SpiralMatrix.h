//
//  SpiralMatrix.h
//  LeetCode
//
//  Created by ipuser on 2015/01/21.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 For example,
 Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 */
#ifndef LeetCode_SpiralMatrix_h
#define LeetCode_SpiralMatrix_h
class SpiralMatrix {
private:
    vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) {
            return res;
        }
        helper(matrix, 0, 0, 0, matrix[0].size() - 1);
        return res;
    }
    void helper(vector<vector<int> > &matrix, int startx, int starty, int endx, int endy) {
        if (startx == endx) {
            if (starty == endy) {
                res.push_back(matrix[startx][starty]);
                return;
            }
            if (starty < endy) {
                for (int i = starty; i < endy; i ++) {
                    res.push_back(matrix[startx][i]);
                }
                helper(matrix, startx+1, endy, 0, 0);
            }
        }
        return;
    }
};
class SpiralMatrix2 {
private:
    vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        helper(matrix);
        return res;
    }
    void helper(vector<vector<int> > &matrix) {
        if (matrix.size() == 0)
            return;
        vector<int> v = matrix[0];
        for(int i = 0; i < v.size(); i ++) {
            res.push_back(v[i]);
        }
        matrix.erase(matrix.begin());
        for(int i = 0; i < matrix.size(); i ++) {
            res.push_back(matrix[i].back());
            matrix[i].pop_back();
        }
        for(int i = matrix.size() - 1; i >=0; i --) {
            if (matrix[i].size() == 0)
                matrix.erase(matrix.begin() + i);
        }
        if (matrix.size() == 0)
            return;
        v = matrix.back();
        for(int i = v.size() - 1; i >= 0; i --) {
            res.push_back(v[i]);
        }
        matrix.erase(matrix.begin() + matrix.size() - 1);
        for(int i = matrix.size() - 1; i >= 0; i --) {
            res.push_back(matrix[i].front());
            matrix[i].erase(matrix[i].begin());
            if (matrix[i].size() == 0)
                matrix.erase(matrix.begin() + i);
        }
        helper(matrix);
    }
};
class SpiralMatrixTest {
public:
    void test() {
        SpiralMatrix2 s;
        vector<vector<int> > o;
        vector<int> v1, v2, v3;
        v1.push_back(1);// v1.push_back(2), v1.push_back(3);
        v2.push_back(4);// v2.push_back(5), v2.push_back(6);
        v3.push_back(7);// v3.push_back(8), v3.push_back(9);
        o.push_back(v1), o.push_back(v2), o.push_back(v3);
        vector<int> res = s.spiralOrder(o);
        for (int i = 0; i < res.size(); i ++) {
            cout << res[i] << ", ";
        }
        cout << endl;
    }
};
#endif
