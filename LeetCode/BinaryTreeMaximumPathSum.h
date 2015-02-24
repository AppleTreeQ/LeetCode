//
//  BinaryTreeMaximumPathSum.h
//  LeetCode
//
//  Created by ipuser on 2015/02/23.
//  Copyright (c) 2015年 ;. All rights reserved.
//

#ifndef LeetCode_BinaryTreeMaximumPathSum_h
#define LeetCode_BinaryTreeMaximumPathSum_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeMaximumPathSum {
private:
    int sum;
public:
    int maxPathSum(TreeNode *root) {
        sum = root->val;
        helper(root);
        return sum;
    }
    int helper(TreeNode *node) {
        if (node == NULL)
            return 0;
        if (node->left == NULL && node->right == NULL) {
            sum = node->val > sum ? node->val : sum;
            return node->val;
        }
        int value1 = helper(node->left), value2 = helper(node->right);
        int path = (value1>0? value1:0) + (value2>0?value2:0) + node->val;
        sum = sum > path ? sum : path;
        return max(node->val, node->val+max(value1, value2));
    }
};
class BinaryTreeMaximumPathSumTest {
public:
    void test() {
        BinaryTreeMaximumPathSum s;
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        cout << s.maxPathSum(root) << endl;
    }
};
#endif
