//
//  ReverseNodesInKGroup.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_ReverseNodesInKGroup_h
#define LeetCode_ReverseNodesInKGroup_h
class ReverseNodesInKGroup {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k <= 1)
            return head;
        ListNode *p1 = head, *p2, *p3;
        int count = 0;
        p3 = head;
        while ( p3 != NULL ) {
            p3 = p3->next;
            count ++;
        }
        if (count < k)
            return head;
        int leftoutPos = count - count % k, pos = 1;
        p2 = head->next;
        head->next = NULL;
        while ( pos < leftoutPos ) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            pos ++;
        }
        ListNode *kgroupHead, *kgroupTail, *kgroupLastHead = p2;
        int s = 0;
        while (p1 != NULL) {
            if (s % k == 0) {
                kgroupHead = p1;
            }
            if (s % k == (k - 1)) {
                kgroupTail = p1;
                p2 = p1->next;
                kgroupTail->next = kgroupLastHead;
                kgroupLastHead = kgroupHead;
                p1 = p2;
                s ++;
                continue;
            }
            p1 = p1->next;
            s ++;
        }
        return kgroupLastHead;
    }
};
class ReverseNodesInKGroupTest {
public:
    void test() {
        ReverseNodesInKGroup solution;
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
        
        result = solution.reverseKGroup(firstforl1,3);
        while(result != NULL) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << endl;
    }
};
#endif
