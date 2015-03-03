//
//  LinkedListCycle.h
//  LeetCode
//
//  Created by ipuser on 2015/03/02.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a linked list, determine if it has a cycle in it.
 
 Follow up:
 Can you solve it without using extra space?
 */
#ifndef LeetCode_LinkedListCycle_h
#define LeetCode_LinkedListCycle_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class LinkedListCycle {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode * next = head, *next2 = head->next->next;
        while (next != NULL && next2 != NULL) {
            if (next == next2)
                return true;
            next = next->next;
            if(next2->next)
                next2 = next2->next->next;
            else
                return false;
        }
        return false;
    }
};
class LinkedListCycleTest {
public:
    void test() {
        
    }
};
#endif
