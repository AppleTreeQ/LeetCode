//
//  ReverseLinkedListII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/15.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 */
#ifndef LeetCode_ReverseLinkedListII_h
#define LeetCode_ReverseLinkedListII_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ReverseLinkedListII {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pre, *cur, *pos1, *pos2, *temp;
        if (m >= n)
            return head;
        int i = 1;
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        cur = newHead;
        //  1->2->3->4->5->NULL
        while (i < m) {
            cur = cur->next;
            i ++;
            continue;
        }
        pos1 = cur;
        cur = cur->next;
        pos1->next = NULL;
        pos2 = cur;
        pre = NULL;
        while (i <= n) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            i ++;
        }
        pos1->next = pre;
        pos2->next = cur;
        head = newHead->next;
        delete[] newHead;
        return head;
    }
};
class ReverseLinkedListIITest {
public:
    void test() {
        int a[] = {1, 2, 3, 4,5};
        ListNode * head, * p;
        p = new ListNode(a[0]);
        head = p;
        for (int i = 1; i < sizeof(a)/sizeof(int); i ++) {
            ListNode *l = new ListNode(a[i]);
            p->next = l;
            p = p->next;
        }
        ReverseLinkedListII s;
        p = s.reverseBetween(head, 2,4);
        while (p != NULL) {
            cout << p->val << "->";
            p = p->next;
        }
        cout <<endl;
    }
};
#endif
