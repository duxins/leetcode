//  82. Remove Duplicates from Sorted List II
//  
//  Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//  For example,
//      Given 1->2->3->3->4->4->5, return 1->2->5.
//      Given 1->1->1->2->3, return 2->3.
//
//  Tags: Linked List
//  
//  https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        ListNode *n = head;
        ListNode *prev = NULL;

        while(n){
            if ((prev == NULL || prev->val != n->val) && (n->next == NULL || n->next->val != n->val)){
                cur->next = n;
                cur = n;
            }
            prev = n;
            n = n->next;
        }

        cur->next = NULL;

        return dummy->next;
    }
};


TEST(leetcode_082_remove_duplicates_from_sorted_list_ii, Basic)
{
    Solution *solution   = new Solution();
    ListNode *head = list_init({1, 2, 3, 3, 4, 4, 5});
    ListNode *expected = list_init({1, 2, 5});
    ListNode *result = solution->deleteDuplicates(head);
    EXPECT_TRUE(list_equal(expected, result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
