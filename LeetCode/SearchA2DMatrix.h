//
//  SearchA2DMatrix.h
//  LeetCode
//
//  Created by ipuser on 2015/01/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SearchA2DMatrix_h
#define LeetCode_SearchA2DMatrix_h
class SearchA2DMatrix {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() < 1)
            return false;
        int x = 0, y = matrix.size() - 1 , a = 0, b = matrix[0].size() - 1;
        return helper(matrix, target, x, y, a, b);
    }
    bool helper(vector<vector<int> > &matrix, int target, int x, int y, int a, int b) {
        if (x == y && a == b) {
            if (matrix[x][a] == target)
                return true;
            else
                return false;
        }
        bool res = false;
        if (x == y && a != b) {
            int mid = (a + b) / 2;
            if (target <= matrix[x][mid])
                return helper(matrix, target, x, x, a, mid);
            else
                return helper(matrix, target, x, x, mid+1, b);
        }
        int mid = (x + y) / 2;
        if (target <= matrix[mid].back())
            return helper(matrix, target, x, mid, a, matrix[mid].size() - 1);
        else
            return helper(matrix, target, mid + 1, y, 0, matrix[y].size() - 1);
        return res;
    }
};
class SearchA2DMatrixTest {
public:
    void test() {
        SearchA2DMatrix s;
        vector<int > v;
        v.push_back(1);
        v.push_back(1);
        vector<vector<int> > vv;
        vv.push_back(v);
        bool res = s.searchMatrix(vv, 2);
        cout << res << endl;
    }
};
#endif
