//
//  PopulatingNextRightPointersInEachNodeII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/18.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_PopulatingNextRightPointersInEachNodeII_h
#define LeetCode_PopulatingNextRightPointersInEachNodeII_h
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class PopulatingNextRightPointersInEachNodeII {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode * cur = root, *head = NULL, *pre = NULL;
        
        while(cur != NULL) {
            if (cur->left == NULL && cur->right == NULL) {
                cur = cur->next;
                continue;
            }
            if (cur->left != NULL && cur->right == NULL) {
                if (pre) {
                    pre->next = cur->left;
                    pre = pre->next;
                } else
                    pre = cur->left;
                if (head == NULL)
                    head = cur->left;
            }
            if (cur->left == NULL && cur->right != NULL) {
                if (pre) {
                    pre->next = cur->right;
                    pre = pre->next;
                } else
                    pre = cur->right;
                if (head == NULL)
                    head = cur->right;
            }
            if (cur->left != NULL && cur->right != NULL) {
                if (head == NULL)
                    head = cur->left;
                if (pre) {
                    pre->next = cur->left;
                    pre = pre->next;
                    pre->next = cur->right;
                    pre = pre->next;
                } else {
                    pre = cur->left;
                    pre->next = cur->right;
                    pre = pre->next;
                }
            }
            cur = cur->next;
        }
        connect(head);
    }
};
class PopulatingNextRightPointersInEachNodeII2 {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> nodes;
        if (root == NULL)
            return;
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            TreeLinkNode * cur = nodes.front();
            nodes.pop();
            if (cur->left) nodes.push(cur->left);
            if (cur->right) nodes.push(cur->right);
            for (int i = 1; i < size; i ++) {
                TreeLinkNode * temp = nodes.front();
                if (temp->left) nodes.push(temp->left);
                if (temp->right) nodes.push(temp->right);
                cur->next = temp;
                cur = temp;
                nodes.pop();
            }
            cur->next = NULL;
        }
        return;
    }
};
class PopulatingNextRightPointersInEachNodeIITest {
public:
    void test() {
        PopulatingNextRightPointersInEachNodeII s;
        TreeLinkNode * root = new TreeLinkNode(1);
        root->left = new TreeLinkNode(2);
        root->right = new TreeLinkNode(3);
        root->left->left = new TreeLinkNode(4);
        root->right->right = new TreeLinkNode(5);
        s.connect(root);
        cout << root->val << root->left->val << root->left->next->val<<endl;
    }
};
#endif
