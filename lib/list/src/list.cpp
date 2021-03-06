//
// Created by Xin Du on 3/6/16.
//

#include <cstdio>
#include <string>
#include <ostream>
#include <vector>
#include "list/list.h"

void list_add_tail(ListNode *head, ListNode *node){
    if(head == NULL) return;

    ListNode *n = head;
    while(n->next){
        n = n->next;
    }
    n->next = node;
}

ListNode *list_init(std::vector<int> v){
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    for(int n : v){
        ListNode *node = new ListNode(n);
        prev->next = node;
        prev = node;
    }

    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

std::vector<int> list_to_vector(ListNode *head){
    std::vector<int> result;
    while(head){
        result.push_back(head->val);
        head = head->next;
    }
    return result;
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


std::ostream& operator <<( std::ostream& os, const ListNode * head) {
    const ListNode *p = head;
    while(p){
        if(p == head){
            os << p->val;
        }else{
            os << ", " << p->val;
        }
        p = p->next;
    }
    return os;
}
