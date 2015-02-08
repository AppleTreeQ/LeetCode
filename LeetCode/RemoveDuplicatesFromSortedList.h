//
//  RemoveDuplicatesFromSortedList.h
//  LeetCode
//
//  Created by ipuser on 2015/02/09.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */
#ifndef LeetCode_RemoveDuplicatesFromSortedList_h
#define LeetCode_RemoveDuplicatesFromSortedList_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class RemoveDuplicatesFromSortedList {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *next1 = head, *next2 = head->next;
        while (next2 != NULL) {
            if (next1->val == next2->val) {
                next1->next = next2->next;
                next2 = next2->next;
            } else {
                next1 = next2;
                next2 = next2->next;
            }
        }
        return head;
    }
};
class RemoveDuplicatesFromSortedListTest {
public:
    void test() {
        
    }
};
#endif
