//
//  PopulatingNextRightPointersInEachNode.h
//  LeetCode
//
//  Created by ipuser on 2015/02/17.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_PopulatingNextRightPointersInEachNode_h
#define LeetCode_PopulatingNextRightPointersInEachNode_h
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class PopulatingNextRightPointersInEachNode {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL)
            return;
        if (root->left != NULL && root->right != NULL) {
            root->left->next = root->right;
            if (root->next != NULL) {
                TreeLinkNode * temp = root->next;
                root->right->next = temp->left;
            }
            connect(root->left);
            connect(root->right);
        }
        return;
    }
    void helper(TreeLinkNode *root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL)
            return;
        if (root->left != NULL && root->right != NULL) {
            root->left->next = root->right;
            if (root->next != NULL) {
                TreeLinkNode * temp = root->next;
                root->right->next = temp->left;
            }
            return;
        }
    }
};
class PopulatingNextRightPointersInEachNodeTest {
public:
    void test() {
        
    }
};
#endif
