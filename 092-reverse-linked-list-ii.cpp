//  92. Reverse Linked List II
//  
//  Reverse a linked list from position m to n. Do it in-place and in one-pass.
//  For example:
//  Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//  return 1->4->3->2->5->NULL.
//  Note:
//  Given m, n satisfy the following condition:
//  1 ≤ m ≤ n ≤ length of list.
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/reverse-linked-list-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;

        ListNode *prev = NULL;
        ListNode *cur = head;

        for(int i = 1; i < m; i++){
            prev = cur;
            cur = cur->next;
        }

        ListNode *nodeM = cur; //m
        ListNode *next = NULL;
        ListNode *nodeN = NULL;

        //Reverse List
        for(int i = m; i <= n; i++){
            next = cur->next;
            cur->next = nodeN;
            nodeN = cur;
            cur = next;
        }

        if(prev == NULL){
            head = nodeN;
        }else{
            prev->next = nodeN;
        }

        nodeM->next = next;

        return head;

    }
};



TEST(leetcode_092_reverse_linked_list_ii, Basic)
{
    Solution *solution = new Solution();
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 4, 3, 2, 5};

    ListNode *head = list_init(nums1, 5);
    ListNode *expected = list_init(nums2, 5);
    EXPECT_TRUE(list_equal(expected, solution->reverseBetween(head, 2, 4)));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
