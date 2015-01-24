//
//  RotateList.h
//  LeetCode
//
//  Created by ipuser on 2015/01/24.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_RotateList_h
#define LeetCode_RotateList_h
/*
 Given a list, rotate the list to the right by k places, where k is non-negative.
 
 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 注意 corner case: ({}, 0), ({1,2}, 0) ({1}, 1)
 */
class RotateList {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode * endNode, *p = head, *lastNode;
        if (head == NULL || k == 0) {
            return head;
        }
        int len = 0;
        while (p != NULL) {
            lastNode = p;
            p = p->next;
            len ++;
        }
        if (len < k)
            k %= len;
        if (k == 0) {
            return head;
        }
        endNode = lastNode;
        p = head;
        for (int i = 0; i < (len - k) ; i ++) {
            lastNode = p;
            p = p->next;
        }
        endNode->next = head;
        head = p;
        lastNode->next = NULL;
        return head;
    }
};
class RotateListTest {
public:
    void test() {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        RotateList s;
        ListNode * res = s.rotateRight(head, 2);
        while (res != NULL) {
            cout << res->val << "->";
            res = res->next;
        }
        cout << endl;
    }
};
#endif
