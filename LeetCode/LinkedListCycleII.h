//
//  LinkedListCycleII.h
//  LeetCode
//
//  Created by ipuser on 2015/03/02.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_LinkedListCycleII_h
#define LeetCode_LinkedListCycleII_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class LinkedListCycleII {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode * next = head, *next2 = head->next->next;
        int len1 = 1, len2 = 3;
        while (next != NULL && next2 != NULL) {
            if (next == next2)
                break;
            next = next->next;
            if(next2->next)
                next2 = next2->next->next;
            else
                return NULL;
            len1 ++;
        }
        
        return NULL;
    }
    ListNode *helper(ListNode *node1, ListNode *node2) {
        return NULL;
    }
};
class LinkedListCycleIITest {
public:
    void test() {
        
    }
};
#endif
