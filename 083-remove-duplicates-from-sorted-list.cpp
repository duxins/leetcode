//  83. Remove Duplicates from Sorted List
//  
//  Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//  For example,
//      Given 1->1->2, return 1->2.
//      Given 1->1->2->3->3, return 1->2->3.
//
//  Tags: Linked List
//  
//  https://leetcode.com/problems/remove-duplicates-from-sorted-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode *p = head;
        ListNode *q = head->next;

        while(q){
            if(p->val == q->val){
                p->next = q->next;
                q = q->next;
            }else{
                p = p->next;
                q = q->next;
            }
        }

        return head;
    }
};

TEST(leetcode_083_remove_duplicates_from_sorted_list, Basic)
{
    Solution *solution = new Solution();
    ListNode *head = list_init({1, 2, 3, 3});
    ListNode *expected = list_init({1, 2, 3});

    ListNode *result = solution->deleteDuplicates(head);

    EXPECT_TRUE(list_equal(expected, result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
