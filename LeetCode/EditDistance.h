//
//  EditDistance.h
//  LeetCode
//
//  Created by ipuser on 2015/01/26.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character
 */
#ifndef LeetCode_EditDistance_h
#define LeetCode_EditDistance_h
class EditDistance {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 == 0)
            return len2;
        if (len2 == 0)
            return len1;
        vector<vector<int> > res(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; i ++) {
            res[i][0] = i;
        }
        for (int i = 0; i <= len2; i ++) {
            res[0][i] = i;
        }
        for (int i = 1; i <= len1; i ++) {
            for (int j = 1; j <= len2; j ++) {
                if (word1[i - 1] == word2[j - 1]) {
                    res[i][j] = res[i - 1][j - 1];
                } else {
                    res[i][j] = min(res[i - 1][j - 1] + 1, min(res[i - 1][j] + 1, res[i][j - 1] + 1));
                }
            }
        }
        return res[len1][len2];
    }
};
class EditDistanceTest {
public:
    void test() {
        
    }
};
#endif
