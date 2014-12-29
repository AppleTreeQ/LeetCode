//
//  SwapNodesInPairs.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_SwapNodesInPairs_h
#define LeetCode_SwapNodesInPairs_h
class SwapNodesInPairs {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = new ListNode(0), *p2 = head, *p3 = head->next;
        p1->next = p2;
        head = head->next;
        while (1) {
            p2->next = p3->next;
            p3->next = p2;
            p1->next = p3;
            p1 = p2;
            p2 = p2->next;
            if (p2 == NULL || p2->next == NULL) {
                break;
            } else
                p3 = p2->next;
        }
        return head;
    }
};
class SwapNodesInPairsTest {
public:
    void test() {
        SwapNodesInPairs solution;
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *firstforl1 = l1, *firstforl2 = l2, *result;
        for ( int i = 0; i < 7; i ++ ) {
            l1->val = i + 1;
            cout << l1->val << "->";
            ListNode *next = new ListNode( i+1 );
            l1->next = next;
            l1 = next;
        }
        cout << "WTF" << endl;
        
        result = solution.swapPairs(firstforl1);
        while(result != NULL) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << endl;
    }
};
#endif
