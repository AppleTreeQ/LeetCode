//
//  BinaryTreeLevelOrderTraversalII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_BinaryTreeLevelOrderTraversalII_h
#define LeetCode_BinaryTreeLevelOrderTraversalII_h
#include <queue>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreeLevelOrderTraversalII {
public:
    //用vector模拟队列
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
            //res.insert(res.begin(), level);
            res.push_back(level);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    // 用队列queue
    vector<vector<int> > levelOrderBottom2(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL)
            return res;
        queue<TreeNode *> nodes;
        vector<int> v;
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; i ++) {
                TreeNode * tn = nodes.front();
                nodes.pop();
                if (tn->left)
                    nodes.push(tn->left);
                if (tn->right)
                    nodes.push(tn->right);
                v.push_back(tn->val);
            }
            res.push_back(v);
            v.clear();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};
class BinaryTreeLevelOrderTraversalIITest {
public:
    void test() {
        BinaryTreeLevelOrderTraversalII s;
        TreeNode * root = new TreeNode(2);
        cout << s.levelOrderBottom2(root).size() << endl;
    }
};
#endif
