//
//  UniquePathsII.h
//  LeetCode
//
//  Created by ipuser on 2015/01/24.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_UniquePathsII_h
#define LeetCode_UniquePathsII_h
class UniquePathsII {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > table(m, vector<int>(n, 1));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) {
                    table[i][j] = 0;
                    continue;
                }
                if (i > 0 && j > 0) {
                    table[i][j] = table[i - 1][j] + table[i][j - 1];
                } else if (i == 0 && j > 0){
                    table[i][j] = table[i][j - 1];
                } else if (j == 0 && i > 0) {
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        return table[m - 1][n - 1];
    }
};
class UniquePathsIITest {
public:
    void test() {
        vector<vector<int> > input(1, vector<int>(2, 0));
        UniquePathsII s;
        int res = s.uniquePathsWithObstacles(input);
        cout << res << endl;
    }
};
#endif
