//
//  RemoveNthNodeFromEndOfList.h
//  LeetCode
//
//  Created by ipuser on 2014/12/29.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_RemoveNthNodeFromEndOfList_h
#define LeetCode_RemoveNthNodeFromEndOfList_h
using namespace std;
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class RemoveNthNodeFromEndOfList {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int sum = 0;
        ListNode * point = head;
        while (point != NULL) {
            sum ++;
            point = point->next;
        }
        point = head;
        int deleteNo = sum - n;
        if ( deleteNo < 0 )
            return head;
        if (deleteNo == 0) {
            head = point->next;
            return head;
        }
        for (int i = 0; i < deleteNo - 1; i ++) {
            point = point->next;
        }
        point->next = point->next->next;
        return head;
    }
};
class RemoveNthNodeFromEndOfListTest {
public:
    void test() {
        int s[] = {1, 2};
        ListNode *head, *p;
        for (int i = 0; i < sizeof(s)/sizeof(int); i ++) {
            ListNode *n = new ListNode(s[i]);
            if (head == NULL) {
                head = n;
                p = n;
            }
            p->next = n;
            p = n;
        }
        RemoveNthNodeFromEndOfList solution;
        p = solution.removeNthFromEnd(head, 1);
        while (p != NULL) {
            cout << p->val << "->";
        }
        cout << endl;
    }
};
#endif
