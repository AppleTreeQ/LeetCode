//
//  RecoverBinarySearchTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Two elements of a binary search tree (BST) are swapped by mistake.
 
 Recover the tree without changing its structure.
 
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */
#ifndef LeetCode_RecoverBinarySearchTree_h
#define LeetCode_RecoverBinarySearchTree_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class RecoverBinarySearchTree {
private:
    vector<int>vect1;
    vector<TreeNode*>vect2;
public:
    void recoverTree(TreeNode *root) {
        helper(root);
        if (vect1.size() < 2) {
            return;
        }
        int pos1 = -1, pos2 = -1;
        for (int i = 1; i < vect1.size(); i ++) {
            if (vect1[i] < vect1[i - 1]) {
                if (pos1 == -1) {
                    pos1 = i - 1;
                }
                pos2 = i;
            }
        }
        swap(vect2[pos1]->val, vect2[pos2]->val);
        return;
    }
    void helper(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        helper(root->left);
        vect1.push_back(root->val);
        vect2.push_back(root);
        helper(root->right);
        return;
    }
    void swap(int &a, int &b) {
        int c = a;
        a = b;
        b = c;
        return;
    }
};
class RecoverBinarySearchTreeTest {
public:
    void test() {
        
    }
};
#endif
