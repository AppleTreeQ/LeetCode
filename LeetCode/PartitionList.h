//
//  PartitionList.h
//  LeetCode
//
//  Created by ipuser on 2015/02/10.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 
 You should preserve the original relative order of the nodes in each of the two partitions.
 
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
 */
#ifndef LeetCode_PartitionList_h
#define LeetCode_PartitionList_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class PartitionList {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return NULL;
        ListNode * head1 = NULL, *head2 = NULL, *next = head, *next1 = NULL, *previous = NULL;
        while (next != NULL) {
            if (next->val < x) {
                if (head1 == NULL) {
                    head1 = next;
                    next1 = next;
                } else {
                    next1->next = next;
                    next1 = next1->next;
                }
                if (previous != NULL) {
                    previous->next = next->next;
                }
                next = next->next;
                next1->next = NULL;
                continue;
            }
            if (next->val >= x){
                if (head2 == NULL)
                    head2 = next;
                previous = next;
                next = next->next;
            }
            
        }
        if (head1 != NULL) {
            next1->next = head2;
            return head1;
        } else
            return head2;
    }
};
class PartitionListTest {
public:
    void test() {
        int a[] = {1};
        ListNode * head = new ListNode(a[0]), *next = head;
        for (int i = 1; i < sizeof(a)/sizeof(int); i ++) {
            ListNode * l = new ListNode(a[i]);
            next->next = l;
            next = next->next;
        }
        PartitionList s;
        next = s.partition(head, 5);
        while (next != NULL) {
            cout << next->val << "->";
            next = next->next;
        }
        cout << endl;
    }
};
#endif
