//  21. Merge Two Sorted Lists
//  
//  Merge two sorted linked lists and return it as a new list.
//  The new list should be made by splicing together the nodes of the first two lists.
//
//  Tags: Linked List
//  
//  https://leetcode.com/problems/merge-two-sorted-lists/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *head = NULL;
        ListNode *prev = NULL;

        while(l1 && l2){
            ListNode *cur;
            if(l1->val < l2->val){
                cur = l1;
                l1 = l1->next;
            }else{
                cur = l2;
                l2 = l2->next;
            }

            if(head == NULL){
                head = cur;
                prev = cur;
            }else{
                prev->next = cur;
                prev = cur;
            }
        }

        prev->next = (l1 == NULL)? l2 : l1;

        return head;
    }

    ListNode* mergeTwoListsRecursively(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoListsRecursively(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoListsRecursively(l2->next, l1);
            return l2;
        }
    }
};

TEST(leetcode_021_merge_two_sorted_lists, Basic)
{
    Solution *solution = new Solution();

    ListNode *head1 = list_init("1, 3, 5, 7");
    ListNode *head2 = list_init("2, 4, 6, 8");

    ListNode *merged = solution->mergeTwoLists(head1, head2);

    ListNode *expected = list_init("1, 2, 3, 4, 5, 6, 7, 8");

    EXPECT_TRUE(list_equal(expected, merged));

}

TEST(leetcode_021_merge_two_sorted_lists, RecursiveSolution)
{
    Solution *solution = new Solution();

    ListNode *head1 = list_init("1, 3, 5, 7");
    ListNode *head2 = list_init("2, 4, 6, 8");

    ListNode *merged = solution->mergeTwoListsRecursively(head1, head2);

    ListNode *expected = list_init("1, 2, 3, 4, 5, 6, 7, 8");

    EXPECT_TRUE(list_equal(expected, merged));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
