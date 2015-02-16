//
//  BinaryTreeZigzagLevelOrderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_BinaryTreeZigzagLevelOrderTraversal_h
#define LeetCode_BinaryTreeZigzagLevelOrderTraversal_h
#include <stack>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode *> currentLevel, nextLevel;
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        currentLevel.push(root);
        vector<int> v;
        int leftToRight = 1;
        while (!currentLevel.empty()) {
            int size = currentLevel.size();
            for (int i = 0; i < size; i ++) {
                TreeNode * tn = currentLevel.top();
                currentLevel.pop();
                if (leftToRight) {
                    if (tn->left)
                        nextLevel.push(tn->left);
                    if (tn->right)
                        nextLevel.push(tn->right);
                } else {
                    if (tn->right)
                        nextLevel.push(tn->right);
                    if (tn->left)
                        nextLevel.push(tn->left);
                }
                v.push_back(tn->val);
            }
            res.push_back(v);
            v.clear();
            swap(currentLevel, nextLevel);
            leftToRight = (leftToRight + 1) % 2;
        }
        return res;
    }
};
class BinaryTreeZigzagLevelOrderTraversalTest {
public:
    void test() {
        
    }
};
#endif
