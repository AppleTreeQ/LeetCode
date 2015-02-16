//
//  ConstructBinaryTreeFromPreorderAndInorderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_ConstructBinaryTreeFromPreorderAndInorderTraversal_h
#define LeetCode_ConstructBinaryTreeFromPreorderAndInorderTraversal_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ConstructBinaryTreeFromPreorderAndInorderTraversal {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() != inorder.size() || preorder.size() == 0 || inorder.size() == 0)
            return NULL;
        return helper(preorder, inorder, 0, 0, preorder.size(), inorder.size());
        
    }
    TreeNode * helper(vector<int> &preorder, vector<int> &inorder, int startp, int starti, int endp, int endi){
        if (starti >= endi || startp >= endp) {
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[startp]);
        int root_index = 0;
        for (root_index = 0; root_index < endi - starti; root_index ++) {
            if (inorder[starti + root_index] == root->val) {
                break;
            }
        }
        root->left = helper(preorder, inorder, startp + 1, starti, startp + root_index + 1, starti + root_index);
        root->right = helper(preorder, inorder, startp + root_index + 1, starti + root_index + 1, endp, endi);
        return root;
    }
};
class ConstructBinaryTreeFromPreorderAndInorderTraversalTest {
public:
    void test() {
        vector<int> preoder, inorder;
        preoder.push_back(1);
        preoder.push_back(2);
        inorder.push_back(1);
        inorder.push_back(2);
        ConstructBinaryTreeFromPreorderAndInorderTraversal s;
        TreeNode *root = s.buildTree(preoder, inorder);
        cout << root->val << endl;
    }
};
#endif