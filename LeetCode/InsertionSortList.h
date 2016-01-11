//
//  InsertionSortList.h
//  LeetCode
//
//  Created by ipuser on 2015/03/04.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//

#ifndef LeetCode_InsertionSortList_h
#define LeetCode_InsertionSortList_h
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class InsertionSortList {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *newHead = new ListNode(head->val - 1);
        newHead->next = head;
        head = newHead;
        ListNode * cur = head->next->next, *pre = head;
        head->next->next = NULL;
        while (cur != NULL) {
            ListNode *sortedCur = head->next;
            ListNode * temp = cur->next;
            cur->next = NULL;
            pre = head;
            while (sortedCur != NULL) {
                if (cur->val < sortedCur->val) {
                    pre->next = cur;
                    cur->next = sortedCur;
                    break;
                }
                pre = pre->next;
                sortedCur = sortedCur->next;
            }
            if(sortedCur == NULL) {
                pre->next = cur;
            }
            cur = temp;
        }
        head = head->next;
        delete newHead;
        return head;
    }
};
class InsertionSortListTest {
public:
    void test() {
        InsertionSortList s;
        ListNode *head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(1);
        head = s.insertionSortList(head);
        ListNode *cur = head;
        while(cur != NULL) {
            cout << cur->val << "->";
            cur = cur->next;
        }
        cout << endl;
    }
};
#endif
