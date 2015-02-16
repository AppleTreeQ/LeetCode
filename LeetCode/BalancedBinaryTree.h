//
//  BalancedBinaryTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
#ifndef LeetCode_BalancedBinaryTree_h
#define LeetCode_BalancedBinaryTree_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return helper(root, height);
        
    }
    bool helper(TreeNode *root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int left_hei = 0, right_hei = 0;
        if (helper(root->left, left_hei) && helper(root->right, right_hei)) {
            if (abs(left_hei - right_hei) <= 1) {
                height = (left_hei > right_hei ? left_hei : right_hei) + 1;
                return true;
            }
        }
        return false;
    }
    //int height()
};
class BalancedBinaryTreeTest {
public:
    void test() {
        
    }
};
#endif
