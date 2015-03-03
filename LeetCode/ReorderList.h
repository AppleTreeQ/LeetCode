//
//  ReorderList.h
//  LeetCode
//
//  Created by ipuser on 2015/03/02.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 
 You must do this in-place without altering the nodes' values.
 
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
#ifndef LeetCode_ReorderList_h
#define LeetCode_ReorderList_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ReorderList {
public:
    void reorderList(ListNode *head) {
        vector<ListNode*> nodes;
        ListNode * cur = head;
        while (cur != NULL) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        int size = nodes.size();
        for (int i = 0; i < size/2; i ++) {
            ListNode *ln1 = nodes[i];
            ListNode *ln2 = nodes[size - i - 1];
            nodes[size - i -2]->next = NULL;
            ln2->next = ln1->next;
            ln1->next = ln2;
        }
        return;
    }
};
class ReorderListTest {
public:
    void test() {
        
    }
};
#endif
