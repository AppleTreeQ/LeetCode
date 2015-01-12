//
//  SameTree.h
//  LeetCode
//
//  Created by ipuser on 2015/01/12.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given two binary trees, write a function to check if they are equal or not.
 
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

#ifndef LeetCode_SameTree_h
#define LeetCode_SameTree_h
class SameTree {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
class SameTreeTest {
public:
    void test() {
        
    }
};
#endif
