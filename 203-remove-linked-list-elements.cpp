//  203. Remove Linked List Elements
//  
//  Remove all elements from a linked list of integers that have value val.
//
//  Example
//      Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
//      Return: 1 --> 2 --> 3 --> 4 --> 5
//
//  Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
//
//  Tags: Linked List
//  
//  https://leetcode.com/problems/remove-linked-list-elements/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            head = head->next;
        }

        if(head == NULL) return NULL;

        ListNode *prev = head;
        ListNode *node = head;

        while(node){
            if(node->val == val){
                prev->next = node->next;
                delete node;
            }else{
                prev = node;
            }
            node = node->next;
        }

        return head;
    }
};

TEST(leetcode_203_remove_linked_list_elements, Basic)
{
    Solution *sol = new Solution();

    ListNode *head = list_init({1, 2, 6, 3, 4, 5, 6});
    ListNode *expected = list_init({1, 2, 3, 4, 5});
    ListNode *result = sol->removeElements(head, 6);
    EXPECT_TRUE(list_equal(expected, result));
}

TEST(leetcode_203_remove_linked_list_elements, Basic2)
{
    Solution *sol = new Solution();

    ListNode *head = list_init({6, 6, 6, 6, 6, 6});
    ListNode *result = sol->removeElements(head, 6);
    EXPECT_EQ(NULL, result);
}

TEST(leetcode_203_remove_linked_list_elements, Basic3)
{
    Solution *sol = new Solution();

    ListNode *head = list_init({6, 6, 6, 6, 1});
    ListNode *expected = list_init({1});
    ListNode *result = sol->removeElements(head, 6);
    EXPECT_TRUE(list_equal(expected, result));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
