//
// Created by Xin Du on 3/6/16.
//

#include "list/list.h"

void list_add_tail(ListNode *head, ListNode *node){
    if(head == NULL) return;

    ListNode *n = head;
    while(n->next){
        n = n->next;
    }
    n->next = node;
}

ListNode *list_init(int *nums, size_t size){
    if(size == 0) return NULL;
    ListNode *head = new ListNode(nums[0]);
    ListNode *prev = head;
    for (int i = 1; i < size; ++i) {
        ListNode *p = new ListNode(nums[i]);
        prev->next = p;
        prev = p;
    }
    return head;
}
