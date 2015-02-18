//
//  FlattenBinaryTreeToLinkedList.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_FlattenBinaryTreeToLinkedList_h
#define LeetCode_FlattenBinaryTreeToLinkedList_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        if (root->left == NULL) {
            flatten(root->right);
            return;
        }
        if (root->right == NULL) {
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode * temp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode *cur = root->right;
        while (cur->right != NULL) {
            cur = cur->right;
        }
        cur->right = temp;
        return;
    }
    void flatten2(TreeNode *root) {
        helper(root);
        return;
    }
    TreeNode * helper(TreeNode *root) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        if (root->left == NULL && root->right != NULL) {
            return helper(root->right);
        }
        if (root->left != NULL && root->right == NULL) {
            TreeNode * tln = helper(root->left);
            root->right = root->left;
            root->left = NULL;
            return tln;
        }
        if (root->left != NULL && root->right != NULL) {
            TreeNode *tln1 = helper(root->left);
            TreeNode *tln2 = helper(root->right);
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            tln1->right = temp;
            return tln2;
        }
        return NULL;
    }
};
class FlattenBinaryTreeToLinkedListTest {
public:
    void test() {
        FlattenBinaryTreeToLinkedList s;
        TreeNode * root = new TreeNode(1);
        root->left = new TreeNode(2);
        //root->right = new TreeNode(3);
        s.flatten2(root);
        TreeNode* cur = root;
        while (cur != NULL) {
            cout << cur->val << "->";
            cur = cur->right;
        }
        cout << endl;
    }
};
#endif
