//  19. Remove Nth Node From End of List
//  
//  Given a linked list, remove the nth node from the end of list and return its head.
//
//  For example,
//      Given linked list: 1->2->3->4->5, and n = 2.
//      After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//  Note:
//      Given n will always be valid.
//      Try to do this in one pass.
//
//  Tags: Linked List, Two Pointers
//  
//  https://leetcode.com/problems/remove-nth-node-from-end-of-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *deleted = slow->next;
        slow->next = deleted->next;
        delete deleted;
        return dummy->next;
    }
};

TEST(leetcode_019_remove_nth_node_from_end_of_list, Basic)
{
    Solution *solution = new Solution();
    ListNode *result = solution->removeNthFromEnd(list_init("1, 2, 3, 4, 5"), 2);
    EXPECT_TRUE(list_equal(list_init("1, 2, 3, 5"), result));

    result = solution->removeNthFromEnd(list_init("1, 2, 3, 4, 5"), 1);
    EXPECT_TRUE(list_equal(list_init("1, 2, 3, 4"), result));

    result = solution->removeNthFromEnd(list_init("1, 2, 3, 4, 5"), 5);
    EXPECT_TRUE(list_equal(list_init("2, 3, 4, 5"), result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
