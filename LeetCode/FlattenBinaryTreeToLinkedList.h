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
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
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
};
class FlattenBinaryTreeToLinkedListTest {
public:
    void test() {
        FlattenBinaryTreeToLinkedList s;
        TreeNode * root = new TreeNode(1);
        root->left = new TreeNode(2);
        //root->right = new TreeNode(3);
        s.flatten(root);
        TreeNode* cur = root;
        while (cur != NULL) {
            cout << cur->val << "->";
            cur = cur->right;
        }
        cout << endl;
    }
};
#endif
