//
//  MergeKSortedLists.h
//  LeetCode
//
//  Created by ipuser on 2015/01/02.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_MergeKSortedLists_h
#define LeetCode_MergeKSortedLists_h
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class MergeKSortedLists {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.size()==0)
            return NULL;
        return helper(lists, 0, (int)lists.size() - 1);
    }
    
private:
    ListNode* helper(vector<ListNode*> &lists, int l, int r) {
        if(l<r) {
            int m = (l+r)/2;
            return merge(helper(lists,l,m),helper(lists,m+1,r));
        }
        return lists[l];
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = l1;
        ListNode* cur = dummy;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                l1 = l1->next;
            }
            else
            {
                ListNode* next = l2->next;
                cur->next = l2;
                l2->next = l1;
                l2 = next;
            }  
            cur = cur->next;
        }  
        if(l2!=NULL) {
            cur->next = l2;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
    
};

class MergeKSortedListsTest {
public:
    void test() {
        MergeKSortedLists solution;
        ListNode *l1;
        ListNode *l2, *result;
        vector<ListNode *> lists;
        lists.push_back(l1);
        lists.push_back(l2);
        result = solution.mergeKLists(lists);
        while(result != NULL) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << endl;
    }
};
#endif



/*
 class Solution {
 public:
 ListNode *mergeKLists(vector<ListNode *> &lists) {
 if (lists.size() < 1)
 return NULL;
 return helper(lists, 0, lists.size() - 1);
 }
 private:
 ListNode *helper(vector<ListNode *> &lists, int l, int r) {
 if (l < r) {
 int m = (l + m) / 2;
 return merge(helper(lists, l, m), helper(lists, m+1, r));
 }
 return lists[l];
 }
 ListNode *merge(ListNode *l1, ListNode *l2) {
 if (l1 == NULL && l2 != NULL)
 return l2;
 if (l2 == NULL && l1 != NULL)
 return l1;
 if (l1 == NULL && l2 == NULL)
 return NULL;
 ListNode *head, *p, *next, *pbak;
 head = l1->val > l2->val ? l2 : l1;
 p = new ListNode(-1);
 pbak = p;
 while (l1 != NULL && l2 != NULL) {
 if (l1->val > l2->val) {
 next = l2;
 l2 = l2->next;
 } else {
 next = l1;
 l1 = l1->next;
 }
 p->next = next;
 p = next;
 }
 if (l1 != NULL) {
 p->next = l1;
 }
 if (l2 != NULL) {
 p->next = l2;
 }
 delete pbak;
 return head;
 }
 };
*/