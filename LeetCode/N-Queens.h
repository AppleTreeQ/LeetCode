//
//  N-Queens.h
//  LeetCode
//
//  Created by ipuser on 2015/01/20.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 */
#ifndef LeetCode_N_Queens_h
#define LeetCode_N_Queens_h
class NQueens {
private:
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> queens;
        vector<int> flag(n, -1);
        findQueens(0, n, flag);
        return res;
    }
    void findQueens(int rowId, int n, vector<int> columnFlg) {
        if (rowId == n) {
            vector<string>queens(n, string(n,'.'));
            for(int i = 0; i < n; i++)
                queens[i][columnFlg[i]] = 'Q';
            res.push_back(queens);
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (check(i, rowId, columnFlg)) {
                columnFlg[rowId] = i;
                findQueens(rowId + 1, n, columnFlg);
                columnFlg[rowId] = -1;
            }
        }
        return;
    }
    bool check(int xpos, int ypos, vector<int> columnFlg) {
        for (int j = 0; j < ypos; j ++) {
            if (columnFlg[j] == xpos || abs(j - ypos) == abs(xpos - columnFlg[j])) {
                return false;
            }
        }
        return true;
    }
};
class NQueensTest {
public:
    void test() {
        NQueens s;
        vector<vector<string> > res, res2;
        res = s.solveNQueens(8);
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                cout << res[i][j] << endl;
            }
            cout << "#########" << endl;
        }
        cout << "hehehehe" << endl;
//        for (int i = 0; i < res2.size(); i ++) {
//            for (int j = 0; j < res2[i].size(); j ++) {
//                cout << res2[i][j] << endl;
//            }
//            cout << "#########" << endl;
//        }
    }
};
#endif
