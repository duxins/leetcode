//  86. Partition List
//  
//  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//  You should preserve the original relative order of the nodes in each of the two partitions.
//
//  For example,
//      Given 1->4->3->2->5->2 and x = 3,
//      return 1->2->2->4->3->5.
//
//  Tags: Linked List, Two Pointers
//  
//  https://leetcode.com/problems/partition-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = NULL, *l2 = NULL;
        ListNode *n1 = NULL, *n2 = NULL;
        ListNode *tail = NULL;
        ListNode *cur = head;

        while(cur){
            ListNode *next = cur->next;
            cur->next = NULL;

            if(cur->val < x) {
                if(l1 == NULL){
                    l1 = cur;
                    n1 = cur;
                }else{
                    n1->next = cur;
                    n1 = cur;
                }
                tail = cur;
            }else{
                if(l2 == NULL){
                    l2 = cur;
                    n2 = cur;
                }else{
                    n2->next = cur;
                    n2 = cur;
                }
            }
            cur = next;
        }

        if(tail) tail->next = l2;

        head = l1 ? l1 : l2;
        return head;
    }
};

TEST(leetcode_086_partition_list, Basic)
{
    Solution *solution = new Solution();
    ListNode *head = list_init({1, 4, 3, 2, 5, 2});
    ListNode *expected = list_init({1, 2, 2, 4, 3, 5});
    EXPECT_TRUE(list_equal(expected, solution->partition(head, 3)));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
