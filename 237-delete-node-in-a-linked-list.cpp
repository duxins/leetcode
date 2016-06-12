//  237. Delete Node in a Linked List
//  
//  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//  Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/delete-node-in-a-linked-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};


TEST(leetcode_237_delete_node_in_a_linked_list, Basic)
{
    ListNode *head = list_init({1, 2, 3, 4, 5});
    Solution *solution = new Solution();
    solution->deleteNode(head->next->next);

    ListNode *result = list_init({1, 2, 4, 5});

    EXPECT_TRUE(list_equal(result, head));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
