//
//  BinaryTreePreorderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/03/03.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_BinaryTreePreorderTraversal_h
#define LeetCode_BinaryTreePreorderTraversal_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreePreorderTraversal {
private:
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == NULL)
            return res;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};
class BinaryTreePreorderTraversal2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        vector<int> res;
        if (root == NULL)
            return res;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode * tn = nodes.top();
            nodes.pop();
            res.push_back(tn->val);
            if (tn->right)
                nodes.push(tn->right);
            if (tn->left)
                nodes.push(tn->left);
        }
        return res;
    }
};
class BinaryTreePreorderTraversalTest {
public:
    void test() {
        
    }
};
#endif
