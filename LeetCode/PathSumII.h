//
//  PathSumII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_PathSumII_h
#define LeetCode_PathSumII_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class PathSumII {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        vector<int> v;
        helper(root, sum, res, v, 0);
        return res;
    }
    void helper(TreeNode *root, int sum, vector<vector<int> >&res, vector<int> vv, int cur_sum) {
        if (root->left == NULL && root->right == NULL) {
            if ((cur_sum + root->val) == sum) {
                vv.push_back(root->val);
                res.push_back(vv);
            }
            return;
        }
        vv.push_back(root->val);
        if (root->left == NULL)
            return helper(root->right, sum, res, vv, cur_sum + root->val);
        if (root->right == NULL)
            return helper(root->left, sum, res, vv, cur_sum + root->val);
        helper(root->left, sum, res, vv, cur_sum + root->val);
        helper(root->right, sum, res, vv, cur_sum + root->val);
    }
};
class PathSumIITest {
public:
    void test() {
        PathSumII s;
        TreeNode * root = new TreeNode(-2);
        root->right = new TreeNode(-3);
        vector<vector<int> > res = s.pathSum(root, -5);
        cout << res.size() << endl;
        cout << res[0][0] << endl;
    }
};
#endif
