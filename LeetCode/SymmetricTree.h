//
//  SymmetricTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree is symmetric:
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 But the following is not:
 1
 / \
 2   2
 \   \
 3    3
 */
#ifndef LeetCode_SymmetricTree_h
#define LeetCode_SymmetricTree_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SymmetricTree {
private:
    vector<int> num;
public:
    bool isSymmetric(TreeNode *root) {
        helper(root);
        int size = num.size();
        for (int i = 0; i < size; i ++) {
            cout << num[i] <<", ";
        }
        cout << endl;
        for (int i = 0; i < size / 2; i ++) {
            if (num[i] != num[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void helper(TreeNode *root) {
        if (root == NULL) {
            num.push_back(-1);
            return;
        }
        helper(root->left);
        num.push_back(root->val);
        helper(root->right);
        return;
    }
};
class SymmetricTreeTest {
public:
    void test() {
        int a[] = {1,2,3,3,0,2,0};
        TreeNode * root = new TreeNode(1);
        TreeNode * r1[7];
        r1[0] = root;
        for (int i = 1; i < 7; i ++) {
            r1[i] = new TreeNode(a[i]);
            if ((i - 1) % 2 == 0) {
                r1[(i-1)/2]->left = r1[i];
            } else
                r1[(i-1)/2]->right = r1[i];
        }
        SymmetricTree s;
        cout << s.isSymmetric(root) << endl;
    }
};
#endif
