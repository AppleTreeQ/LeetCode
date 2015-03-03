//
//  CopyListWithRandomPointer.h
//  LeetCode
//
//  Created by ipuser on 2015/03/02.
//  Copyright (c) 2015年 qzhai. All rights reserved.
//
/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
 Return a deep copy of the list.
 */
#ifndef LeetCode_CopyListWithRandomPointer_h
#define LeetCode_CopyListWithRandomPointer_h
/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class CopyListWithRandomPointer {
private:
    map<int, RandomListNode*> nodes;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        if (nodes[head->label] != NULL)
            return nodes[head->label];
        RandomListNode *newNode = new RandomListNode(head->label);
        nodes[head->label] = newNode;
        if (head->next == NULL)
            newNode->next = NULL;
        else
            newNode->next = copyRandomList(head->next);
        if (head->random != NULL) {
            newNode->random = nodes[head->random->label];
        }
        return newNode;
    }
};
class CopyListWithRandomPointer2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        map<int, RandomListNode*> nodes;
        vector<RandomListNode*> remains;
        RandomListNode *next = head, *head2 = new RandomListNode(-1), *pre = head2;
        while (next != NULL) {
            RandomListNode *newNode = new RandomListNode(next->label);
            nodes[next->label] = newNode;
            if (next->random) {
                if (nodes[next->random->label])
                    newNode->random = nodes[next->random->label];
                else
                    remains.push_back(next);
            }
            pre->next = newNode;
            pre = pre->next;
            next = next->next;
        }
        for (int i = 0; i < remains.size(); i ++) {
            RandomListNode *n = remains[i];
            nodes[n->label]->random = nodes[n->random->label];
        }
        pre = head2->next;
        delete head2;
        return pre;
    }
};
class CopyListWithRandomPointer3 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return NULL;
    }
};
class CopyListWithRandomPointerTest {
public:
    void test() {
        
    }
};
#endif
