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

void judge(vector<int> input1, vector<int> input2, vector<int> expected){
    Solution solution = Solution();
    ListNode *l1 = list_init(input1);
    ListNode *l2 = list_init(input2);
    EXPECT_EQ(expected, list_to_vector(solution.addTwoNumbers(l1, l2)));
}

TEST(leetcode_002_add_two_numbers, Basic)
{
    judge({0}, {0}, {0});
    judge({2, 4, 3, 9}, {5, 6, 6}, {7, 0, 0, 0, 1});
    judge({2, 4, 3},{5, 6, 4}, {7, 0, 8});
    judge({9, 1, 6},{0}, {9, 1, 6});
    judge({9}, {1,9,9,9,9,9,9,9,9,9}, {0,0,0,0,0,0,0,0,0,0,1});
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
