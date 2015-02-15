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
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
    bool compare(TreeNode* l, TreeNode* r) {
        if (l == r && l == NULL) return true;
        if (l == NULL || r == NULL) return false;
        if (l->val != r->val) return false;
        if (!compare(l->left, r->right)) return false;
        if (!compare(l->right, r->left)) return false;
        return true;
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
