//
// Created by Xin Du on 3/6/16.
//

#include <cstdio>
#include <string>
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

ListNode *list_init(std::string str){
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    int n = 0;
    for(auto c: str){
        if(!isdigit(c) && c != ',') continue;
        if(c == ','){
            ListNode *node = new ListNode(n);
            prev->next = node;
            prev = node;
            n = 0;
        }else{
            n = n * 10 + (c - '0');
        }
    }
    if(n > 0){
        prev->next = new ListNode(n);
    }
    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

bool list_equal(ListNode *head1, ListNode *head2){
    ListNode *p = head1;
    ListNode *q = head2;

    while(p && q){
        if(p->val != q->val) return false;
        p = p->next;
        q = q->next;
    }

    if(p == NULL && q == NULL) return true;

    return false;
}

void list_print(ListNode *head){
    ListNode *p = head;
    while(p){
        if(p == head){
            printf("%d", p->val);
        }else{
            printf(" -> %d ", p->val);
        }
        p = p->next;
    }
    printf("\n");
}
