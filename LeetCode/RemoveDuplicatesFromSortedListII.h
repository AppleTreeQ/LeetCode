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
        
    }
};
class RemoveDuplicatesFromSortedListIITest {
public:
    void test() {
        
    }
};
#endif
