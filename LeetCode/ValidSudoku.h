//
//  ValidSudoku.h
//  LeetCode
//
//  Created by ipuser on 2015/01/05.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 */
#ifndef LeetCode_ValidSudoku_h
#define LeetCode_ValidSudoku_h
class ValidSudoku {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rowVaild[10] = {0};
        int columnValid[9][10] = {0};
        int subBoardValid[9][10] = {0};
        for (int i = 0; i < 9; i ++) {
            memset(rowVaild, 0, sizeof(rowVaild));
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    if (!checkValid(rowVaild, board[i][j] - '0') ||
                        !checkValid(columnValid[j], board[i][j] - '0') ||
                        !checkValid(subBoardValid[i/3*3+j/3], board[i][j] - '0'))
                        return false;
                }
            }
        }
        return true;
    }
    bool checkValid(int vec[], int i) {
        if (vec[i] == 1) return false;
        vec[i] = 1;
        return true;
    }
};
class ValidSudokuTest {
public:
    void test() {
        
    }
};
#endif
