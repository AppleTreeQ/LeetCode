//
//  UniqueBinarySearchTreesII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_UniqueBinarySearchTreesII_h
#define LeetCode_UniqueBinarySearchTreesII_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class UniqueBinarySearchTreesII {
public:
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }
    vector<TreeNode *> helper(int start, int end) {
        vector<TreeNode *> vv;
        if (start > end) {
            vv.push_back(NULL);
            return vv;
        }
        for (int i = start; i <= end; i ++) {
            vector<TreeNode *>temp1 = helper(start, i - 1);
            vector<TreeNode *>temp2 = helper(i + 1, end);
            for (int m = 0; m < temp1.size(); m ++) {
                for (int n = 0; n < temp2.size(); n ++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = temp1[m];
                    root->right = temp2[n];
                    vv.push_back(root);
                }
            }
        }
        return vv;
    }
};
class UniqueBinarySearchTreesIITest {
public:
    void test() {
        UniqueBinarySearchTreesII s;
        vector<TreeNode *> res = s.generateTrees(2);
        cout << res.size() << endl;
        
    }
};
#endif
