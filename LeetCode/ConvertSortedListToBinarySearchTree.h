//
//  ConvertSortedListToBinarySearchTree.h
//  LeetCode
//
//  Created by ipuser on 2015/02/16.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
//1->2->3->4
#ifndef LeetCode_ConvertSortedListToBinarySearchTree_h
#define LeetCode_ConvertSortedListToBinarySearchTree_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class ConvertSortedListToBinarySearchTree {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode * cur = head;
        int count = 0;
        while (cur != NULL) {
            count ++;
            cur = cur->next;
        }
        return helper(head, 0, count);
    }
    TreeNode *helper(ListNode *head, int start, int end){
        if (head == NULL || start >= end)
            return NULL;
        int index = (start + end) / 2, i = start;
        ListNode * cur = head;
        while (i < index) {
            cur = cur->next;
            i ++;
        }
        TreeNode * root = new TreeNode(cur->val);
        root->left = helper(head, start, index);
        root->right = helper(cur->next, index + 1, end);
        return root;
    }
};
class ConvertSortedListToBinarySearchTreeTest {
public:
    void test() {
        ListNode *l1 = new ListNode(3);
        l1->next = new ListNode(5);
        l1->next->next = new ListNode(8);
        ConvertSortedListToBinarySearchTree s;
        cout << s.sortedListToBST(l1)->val << endl;
    }
};
#endif
