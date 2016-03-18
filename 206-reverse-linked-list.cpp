//  206. Reverse Linked List
//  
//  Reverse a singly linked list.
//  click to show more hints.
//  Hint:
//  A linked list can be reversed either iteratively or recursively. Could you implement both?
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/reverse-linked-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode *prev = NULL;
        while(head){
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

TEST(leetcode_206_reverse_linked_list, Basic)
{
    Solution *solution = new Solution();
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {5, 4, 3, 2, 1};

    ListNode *head = list_init(nums1, 5);
    ListNode *expected = list_init(nums2, 5);

    EXPECT_TRUE(list_equal(expected, solution->reverseList(head)));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
