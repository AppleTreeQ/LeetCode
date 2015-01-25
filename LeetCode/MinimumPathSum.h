//
//  MinimumPathSum.h
//  LeetCode
//
//  Created by ipuser on 2015/01/25.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 Note: You can only move either down or right at any point in time.
 */
#ifndef LeetCode_MinimumPathSum_h
#define LeetCode_MinimumPathSum_h
class MinimumPathSum {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i > 0 && j > 0) {
                    grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
                } else if (i == 0 && j > 0){
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0 && i > 0) {
                    grid[i][j] += grid[i - 1][j];
                }
            }
        }
        return grid[m - 1][n - 1];
    }
};
class MinimumPathSumTest {
public:
    void test() {
        
    }
};
#endif
