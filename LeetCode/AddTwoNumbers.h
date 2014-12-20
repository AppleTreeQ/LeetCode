//
//  AddTwoNumbers.h
//  LeetCode
//
//  Created by ipuser on 2014/12/21.
//  Copyright (c) 2014年 ipuser. All rights reserved.
//

#ifndef LeetCode_AddTwoNumbers_h
#define LeetCode_AddTwoNumbers_h

#include <iostream>
#include "stdlib.h"
using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if ( l1 == NULL && l2 == NULL ) {
            cout << "error!" << endl;
            return NULL;
        }
        
        ListNode *result = new ListNode(0);
        ListNode *first = result;
        int temp = 0;
        while ( l1 != NULL || l2 != NULL ) {
            if (l1 == NULL) {
                ListNode *newl1 = new ListNode(0);
                l1 = newl1;
            }
            if (l2 == NULL) {
                ListNode *newl2 = new ListNode(0);
                l2 = newl2;
            }
            if (( temp + l1->val + l2->val )> 9 ) {
                result->val = temp + l1->val + l2->val - 10;
                temp = 1;
            } else {
                result->val = temp + l1->val + l2->val;
                temp = 0;
            }
            ListNode *result2 = new ListNode(0);
            result->next = result2;
            result = result2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (temp > 0){
            result->val = temp;
            
        }
        return first;
    }
};

class AddTwoNumbersTest {
public:
    void test() {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *firstforl1 = l1, *firstforl2 = l2, *result;
        for ( int i = 0; i < 5; i ++ ) {
            l1->val = rand() % 10;
            cout << l1->val << "->";
            ListNode *next = new ListNode(0);
            l1->next = next;
            l1 = next;
        }
        cout << endl;
        for ( int i = 0; i < 5; i ++ ) {
            l2->val = rand() % 10;
            cout << l2->val << "->";
            ListNode *next = new ListNode(0);
            l2->next = next;
            l2 = next;
        }
        cout << endl;
        AddTwoNumbers solution;
        result = solution.addTwoNumbers(firstforl1, firstforl2);
        while(result != NULL) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << endl;
    }
};
#endif
