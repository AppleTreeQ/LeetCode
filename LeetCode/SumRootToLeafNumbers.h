//
//  SumRootToLeafNumbers.h
//  LeetCode
//
//  Created by ipuser on 2015/02/22.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_SumRootToLeafNumbers_h
#define LeetCode_SumRootToLeafNumbers_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SumRootToLeafNumbers {
public:
    int sumNumbers(TreeNode *root) {
        vector<int> res;
        helper(root, res, 0);
        int sum = 0;
        for (int i = 0; i < res.size(); i ++) {
            sum += res[i];
        }
        return sum;
    }
    void helper(TreeNode *node, vector<int> & res, int num) {
        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL) {
            res.push_back(num*10+node->val);
            return;
        }
        helper(node->left, res, num*10+node->val);
        helper(node->right, res, num*10+node->val);
        return;
    }
};
class SumRootToLeafNumbersTest {
public:
    void test() {
        SumRootToLeafNumbers s;
    }
};
#endif
