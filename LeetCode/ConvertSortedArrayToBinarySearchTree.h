//
//  ConvertSortedArrayToBinarySearchTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#ifndef LeetCode_ConvertSortedArrayToBinarySearchTree_h
#define LeetCode_ConvertSortedArrayToBinarySearchTree_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ConvertSortedArrayToBinarySearchTree {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return NULL;
        return helper(num, 0, num.size());
    }
    TreeNode *helper(vector<int> &num, int start, int end) {
        if (start >= end)
            return NULL;
        int index = (start + end) / 2;
        TreeNode * root = new TreeNode(num[index]);
        root->left = helper(num, start, index);
        root->right = helper(num, index + 1, end);
        return root;
    }
};
class ConvertSortedArrayToBinarySearchTreeTest {
public:
    void test() {
        
    }
};
#endif
