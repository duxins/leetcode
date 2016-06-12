//  2. Add Two Numbers
//  
//  You are given two linked lists representing two non-negative numbers.
//  The digits are stored in reverse order and each of their nodes contain a single digit.
//  Add the two numbers and return it as a linked list.
//
//  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//  Output: 7 -> 0 -> 8
//
//  Tags: Linked List, Math
//  
//  https://leetcode.com/problems/add-two-numbers/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *dummy = new ListNode(-1);
        ListNode *node  = dummy;

        int carry = 0;

        while(l1 || l2){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ListNode *n = new ListNode(sum % 10);
            node->next = n;
            node = n;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry > 0){
            node->next = new ListNode(carry);
        }

        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

TEST(leetcode_002_add_two_numbers, Basic)
{
    Solution *solution = new Solution();
    ListNode *l1 = list_init({2, 4, 3, 9});
    ListNode *l2 = list_init({5, 6, 6});
    ListNode *expected = list_init({7, 0, 0, 0, 1});
    EXPECT_TRUE(list_equal(expected, solution->addTwoNumbers(l1, l2)));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
