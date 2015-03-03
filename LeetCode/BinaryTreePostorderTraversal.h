//
//  BinaryTreePostorderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/03/03.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_BinaryTreePostorderTraversal_h
#define LeetCode_BinaryTreePostorderTraversal_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BinaryTreePostorderTraversal {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        vector<int> res;
        if (root == NULL)
            return res;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode * tn = nodes.top();
            nodes.pop();
            res.push_back(tn->val);
            if (tn->left)
                nodes.push(tn->left);
            if (tn->right)
                nodes.push(tn->right);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
class BinaryTreePostorderTraversalTest {
public:
    void test() {
        
    }
};
#endif
