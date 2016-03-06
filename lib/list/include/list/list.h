//
// Created by Xin Du on 3/6/16.
//

#include <cstddef>

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct LinkedList {
    ListNode *head;
    ListNode *tail;
    LinkedList(ListNode *head): head(head), tail(head) {}
};

ListNode *list_init(int *nums, size_t size);

void list_add_tail(ListNode *head, ListNode *node);

#endif //LEETCODE_LIST_H
