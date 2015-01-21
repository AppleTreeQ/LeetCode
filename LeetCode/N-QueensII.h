//
//  N-QueensII.h
//  LeetCode
//
//  Created by ipuser on 2015/01/21.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_N_QueensII_h
#define LeetCode_N_QueensII_h
class N_QueensII {
private:
    int res;
public:
    int totalNQueens(int n) {
        vector<string> queens;
        vector<int> flag(n, -1);
        res = 0;
        findQueens(0, n, flag);
        return res;
    }
    void findQueens(int rowId, int n, vector<int> columnFlg) {
        if (rowId == n) {
            res ++;
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
class N_QueensIITest {
public:
    void test() {
        N_QueensII s;
        cout << s.totalNQueens(8) << endl;
    }
};
#endif
