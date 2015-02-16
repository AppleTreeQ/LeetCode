//
//  ConstructBinaryTreeFromInorderAndPostorderTraversal.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given inorder and postorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
   1
 /   \
 2   3
 \   /
 4   5
 inorder   24153
 postorder 42531
 */
#ifndef LeetCode_ConstructBinaryTreeFromInorderAndPostorderTraversal_h
#define LeetCode_ConstructBinaryTreeFromInorderAndPostorderTraversal_h
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ConstructBinaryTreeFromInorderAndPostorderTraversal {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() != postorder.size() || inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return helper(inorder, postorder, 0, 0, inorder.size(), postorder.size());
    }
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int starti, int startp, int endi, int endp) {
        if (starti >= endi || startp >= endp)
            return NULL;
        TreeNode * root = new TreeNode(postorder[endp - 1]);
        int root_index = 0;
        for (; root_index < endi - starti; root_index ++) {
            if (inorder[starti + root_index] == root->val) {
                break;
            }
        }
        root->left = helper(inorder, postorder, starti, startp, starti + root_index, startp + root_index);
        root->right = helper(inorder, postorder, starti + root_index + 1, startp + root_index, endi, endp - 1);
        return root;
    }
};
class ConstructBinaryTreeFromInorderAndPostorderTraversalTest {
public:
    void test() {
        vector<int> postorder, inorder;
        postorder.push_back(1);
        postorder.push_back(2);
        inorder.push_back(1);
        inorder.push_back(2);
        ConstructBinaryTreeFromInorderAndPostorderTraversal s;
        TreeNode *root = s.buildTree(inorder, postorder);
        cout << root->val << endl;
    }
};
#endif
