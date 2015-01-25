//
//  UniquePaths.h
//  LeetCode
//
//  Created by ipuser on 2015/01/24.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_UniquePaths_h
#define LeetCode_UniquePaths_h
class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        int t = m + n - 2;
        int x = m - 1, y = n - 1;
        long dd = 1, dr = 1;
        if (x > y)
            swap(x, y);
        for (int i = 1; i <= t; i ++) {
            if (i <= x) {
                dr *= i;
            }
            if (i > y) {
                dd *= i;
            }
        }
        return dd / dr;
    }
    void swap(int &a, int &b) {
        int c = a;
        a = b;
        b = c;
    }
    // (m + n)!/(m!*n!), long int会溢出，double不精确。放弃
    double factorials(int x) {
        double res = 1;
        for (int i = 1; i <= x; i ++) {
            res *= i;
        }
        return res;
    }
};
//用回溯
class UniquePaths2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > table(m, vector<int>(n, 1));
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
        }
        return table[m - 1][n - 1];
    }
};
class UniquePaths3 {
private:
    int count;
public:
    int uniquePaths(int m, int n) {
        count = 0;
        findPaths(0, 0, m - 1, n - 1);
        return count;
    }
    //这种方法，时间太长。
    void findPaths(int startx, int starty, int endx, int endy) {
        if (startx > endx || starty > endy) {
            return;
        }
        if (startx == endx && starty == endy) {
            count ++;
            return;
        }
        findPaths(startx + 1, starty, endx, endy);
        findPaths(startx, starty + 1, endx, endy);
    }
};
class UniquePathsTest {
public:
    void test() {
        UniquePaths2 s;
        int res = s.uniquePaths(2, 100);
        cout << res << endl;
    }
};
#endif
