//
//  RemoveDuplicatesFromSortedListII.h
//  LeetCode
//
//  Created by ipuser on 2015/02/09.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 */
#ifndef LeetCode_RemoveDuplicatesFromSortedListII_h
#define LeetCode_RemoveDuplicatesFromSortedListII_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class RemoveDuplicatesFromSortedListII {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *point1 = new ListNode(-1), *point2 = head, *point3 = head->next;
        point1->next = head;
        head = point1;
        bool flag = false;
        while (point3 != NULL) {
            if (point2->val == point3->val) {
                point3 = point3->next;
                flag = true;
            } else {
                if (flag) {
                    point1->next=point3;
                    point2 = point3;
                    point3 = point3->next;
                    flag = false;
                } else {
                    point3 = point3->next;
                    point2 = point2->next;
                    point1 = point1->next;
                }
            }
        }
        if (flag) {
            point1->next=point3;
        }
        point1 = head;
        head = head->next;
        delete point1;
        return head;
    }
};
class RemoveDuplicatesFromSortedListIITest {
public:
    void test() {
        int a[] = {1, 2, 3, 3, 4, 4, 5};
        ListNode * head, * p;
        p = new ListNode(a[0]);
        head = p;
        for (int i = 1; i < sizeof(a)/sizeof(int); i ++) {
            ListNode *l = new ListNode(a[i]);
            p->next = l;
            p = p->next;
        }
        RemoveDuplicatesFromSortedListII s;
        head = s.deleteDuplicates(head);
        p = head;
        while (p != NULL) {
            cout << p->val << "->";
            p = p->next;
        }
        cout << endl;
    }
};
#endif
