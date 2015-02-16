//
//  PathSum.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
#ifndef LeetCode_PathSum_h
#define LeetCode_PathSum_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class PathSum {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;
        return helper(root, sum, 0);
    }
    bool helper(TreeNode *root, int sum, int cur_sum) {
        if (root->left == NULL && root->right == NULL) {
            if ((cur_sum + root->val) == sum)
                return true;
            else
                return false;
        }
        if (root->left == NULL)
            return helper(root->right, sum, cur_sum + root->val);
        if (root->right == NULL)
            return helper(root->left, sum, cur_sum + root->val);
        return helper(root->left, sum, cur_sum + root->val) || helper(root->right, sum, cur_sum + root->val);
    }
};
class PathSumTest {
public:
    void test() {
        PathSum s;
        
    }
};
#endif
