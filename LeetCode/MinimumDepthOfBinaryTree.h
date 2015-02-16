//
//  MinimumDepthOfBinaryTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a binary tree, find its minimum depth.
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
#ifndef LeetCode_MinimumDepthOfBinaryTree_h
#define LeetCode_MinimumDepthOfBinaryTree_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class MinimumDepthOfBinaryTree {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int left_hei = INT_MAX, right_hei = INT_MAX;
        if (root->left)
            left_hei = minDepth(root->left);
        if (root->right)
            right_hei = minDepth(root->right);
        return (left_hei < right_hei ? left_hei : right_hei) + 1;
    }
};
class MinimumDepthOfBinaryTreeTest {
public:
    void test() {
        
    }
};
#endif
