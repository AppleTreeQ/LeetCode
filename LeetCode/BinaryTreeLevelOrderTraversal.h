//
//  BinaryTreeLevelOrderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_BinaryTreeLevelOrderTraversal_h
#define LeetCode_BinaryTreeLevelOrderTraversal_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeLevelOrderTraversal {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        vector<TreeNode *> nodes;
        nodes.push_back(root);
        int end = nodes.size(), i = 0, start = 0, increase = 0;
        while (i < end) {
            vector<int> level;
            increase = 0;
            for (i = start; i < end; i ++) {
                TreeNode * tn = nodes[i];
                if (tn->left != NULL) {
                    nodes.push_back(tn->left);
                    increase ++;
                }
                if (tn->right != NULL) {
                    nodes.push_back(tn->right);
                    increase ++;
                }
                level.push_back(tn->val);
            }
            start = end;
            end += increase;
            res.push_back(level);
        }
        return res;
    }
};
class BinaryTreeLevelOrderTraversalTest {
public:
    void test() {
        
    }
};
#endif
