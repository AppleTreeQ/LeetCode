//
//  MergeKSortedLists.h
//  LeetCode
//
//  Created by ipuser on 2015/01/02.
//  Copyright (c) 2015年 ipuser. All rights reserved.
//

#ifndef LeetCode_MergeKSortedLists_h
#define LeetCode_MergeKSortedLists_h

class MergeKSortedLists {
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
        delete[] pbak;
        return head;
    }
};
class MergeKSortedListsTest {
public:
    void test() {
        MergeKSortedLists solution;
        ListNode *l1 = new ListNode(0);
        ListNode *firstforl1 = l1, *result;
        for ( int i = 0; i < 7; i ++ ) {
            l1->val = i + 1;
            cout << l1->val << "->";
            ListNode *next = new ListNode( i+1 );
            l1->next = next;
            l1 = next;
        }
        l1->val = 9;
        cout << l1->val << endl;
        vector<ListNode *> lists;
        lists.push_back(NULL);
        lists.push_back(NULL);
        result = solution.mergeKLists(lists);
        while(result != NULL) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << endl;
    }
};
#endif
