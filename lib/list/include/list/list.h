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

bool list_equal(ListNode *head1, ListNode *head2);

void list_print(ListNode *head);

#endif //LEETCODE_LIST_H
