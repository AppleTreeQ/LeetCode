//
//  BinaryTreeInorderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_BinaryTreeInorderTraversal_h
#define LeetCode_BinaryTreeInorderTraversal_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeInorderTraversal {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        helper(root);
        return res;
    }
    void helper(TreeNode * root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            inorderTraversal(root->left);
        }
        res.push_back(root->val);
        if (root->right != NULL) {
            inorderTraversal(root->right);
        }
        return;
    }
};
class BinaryTreeInorderTraversalTest {
public:
    void test() {
        
    }
};
#endif
