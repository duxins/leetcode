//  24. Swap Nodes in Pairs
//  
//  Given a linked list, swap every two adjacent nodes and return its head.
//  For example,
//  Given 1->2->3->4, you should return the list as 2->1->4->3.
//  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/swap-nodes-in-pairs/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *n = head->next;
        head->next = swapPairs(n->next);
        n->next = head;
        return n;
    }
};

TEST(leetcode_024_swap_nodes_in_pairs, Basic)
{
    Solution *solution = new Solution();
    int nums1[] = {1, 2, 3, 4};
    int nums2[] = {2, 1, 4, 3};
    ListNode *head = list_init(nums1, 4);
    ListNode *expected = list_init(nums2, 4);
    EXPECT_TRUE(list_equal(expected, solution->swapPairs(head)));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
