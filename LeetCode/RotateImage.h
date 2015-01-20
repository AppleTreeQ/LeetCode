//
//  RotateImage.h
//  LeetCode
//
//  Created by ipuser on 2015/01/19.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?
 */
#ifndef LeetCode_RotateImage_h
#define LeetCode_RotateImage_h
class RotateImage {
public:
    void rotate(vector<vector<int> > &matrix) {
        int tmp, n = matrix.size();
        for (int i = 0; i < matrix.size() / 2; i ++) {
            for ( int j = i; j < n - i - 1; j ++) {
                /*
                 the postions of four corresponding pixels are (i, j), (j, n - 1 - i), (n - 1 - i, n - 1 - j), (n - 1 -j, i)
                 */
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};
class RotateImageTest {
public:
    void test() {
        
    }
};
#endif
