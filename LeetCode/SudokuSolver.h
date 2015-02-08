//
//  SudokuSolver.h
//  LeetCode
//
//  Created by ipuser on 2015/02/08.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SudokuSolver_h
#define LeetCode_SudokuSolver_h
class SudokuSolver {
public:
    void solveSudoku(vector<vector<char> > &board) {
        bool flag = false;
        helper(board, 0, flag);
    }
    void helper(vector<vector<char> > &board, int num, bool &flag) {
        int x = num/9, y = num % 9;
        if (flag) {
            return;
        }
        if (num >= 81) {
            flag = true;
            return;
        }
        if (board[x][y] != '.') {
            helper(board, num + 1, flag);
            return;
        }
        for (int i = 1; i <= 9; i ++) {
            if (searchRow(board, x, i) && searchCol(board, y, i) && searchGrid(board, x, y, i)) {
                board[x][y] = '0' + i;
                helper(board, num + 1, flag);
                if (flag) {
                    return;
                }
            }
        }
        board[x][y] = '.';
        return;
    }
    bool searchRow(vector<vector<char> > &board, int x, int target) {
        for (int i = 0; i < 9; i ++) {
            int diff = board[x][i] - '0';
            if (diff >= 1 && diff <= 9 && diff == target)
                return false;
        }
        return true;
    }
    bool searchCol(vector<vector<char> > &board, int y, int target) {
        for (int i = 0; i < 9; i ++) {
            int diff = board[i][y] - '0';
            if (diff >= 1 && diff <= 9 && diff == target)
                return false;
        }
        return true;
    }
    bool searchGrid(vector<vector<char> > &board, int x, int y, int target) {
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                int diff = board[x/3*3 + i][y/3*3 + j] - '0';
                if (diff >= 1 && diff <= 9 && diff == target)
                    return false;
            }
        }
        return true;
    }
};
class SudokuSolverTest {
public:
    void test() {
        char c[9][10] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
        vector<vector<char> > vec;
        for (int i = 0; i < 9; i ++) {
            vector<char> v;
            v.insert(v.end(), c[i], c[i] + 9);
            vec.push_back(v);
        }
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
        SudokuSolver s;
        s.solveSudoku(vec);
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
    }
};
#endif
