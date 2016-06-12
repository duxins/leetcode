//  328. Odd Even Linked List
//  
//  Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//  Example:
//  Given 1->2->3->4->5->NULL,
//  return 1->3->5->2->4->NULL.
//  Note:
//  The relative order inside both the even and odd groups should remain as it was in the input. 
//  The first node is considered odd, the second node even and so on ...
//  Credits:Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/odd-even-linked-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *odd = head;
        ListNode *even = head->next;

        ListNode *node = even;

        while(node && node->next){
            odd->next = node->next;
            odd = node->next;
            node->next = node->next->next;
            node = node->next;
        }

        odd->next = even;

        return head;
    }
};


TEST(leetcode_328_odd_even_linked_list, Basic)
{
    Solution *solution = new Solution();

    ListNode *head = list_init({1, 2, 3, 4, 5});
    ListNode *expected = list_init({1, 3, 5, 2, 4});

    ListNode *result = solution->oddEvenList(head);

    list_print(result);

    EXPECT_TRUE(list_equal(expected, result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
