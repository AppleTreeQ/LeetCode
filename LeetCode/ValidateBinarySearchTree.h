//
//  ValidateBinarySearchTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a binary tree, determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 */
#ifndef LeetCode_ValidateBinarySearchTree_h
#define LeetCode_ValidateBinarySearchTree_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ValidateBinarySearchTree {
private:
    vector<int> num;
public:
    bool isValidBST(TreeNode *root) {
        helper(root);
        for (int i = 0; i < num.size(); i ++) {
            if (i > 0 && num[i] <= num[i - 1]) {
                return false;
            }
        }
        return true;
    }
    void helper(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        helper(root->left);
        num.push_back(root->val);
        helper(root->right);
        return;
    }
};
class ValidateBinarySearchTreeTest {
public:
    void test() {
        
    }
};
#endif
