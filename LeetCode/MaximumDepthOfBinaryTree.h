//
//  MaximumDepthOfBinaryTree.h
//  LeetCode
//
//  Created by ipuser on 2015/01/09.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a binary tree, find its maximum depth.
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#ifndef LeetCode_MaximumDepthOfBinaryTree_h
#define LeetCode_MaximumDepthOfBinaryTree_h
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return getDepth(root);
    }
    int getDepth(TreeNode *node) {
        if (node->left == NULL && node->right == NULL)
            return 1;
        int leftDepth = 0, rightDepth = 0;
        if (node->left != NULL) {
            leftDepth = getDepth(node->left);
        }
        if (node->right != NULL) {
            rightDepth = getDepth(node->right);
        }
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};
class MaximumDepthOfBinaryTreeTest {
public:
    void test() {
        MaximumDepthOfBinaryTree solution;
    }
};
#endif
