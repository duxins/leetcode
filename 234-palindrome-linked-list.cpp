//  234. Palindrome Linked List
//  
//  Given a singly linked list, determine if it is a palindrome.
//  Follow up:
//  Could you do it in O(n) time and O(1) space?
//
//  Tags: Linked List, Two Pointers
//  
//  https://leetcode.com/problems/palindrome-linked-list/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)  return true;
        int count = 0;

        ListNode *node = head;
        while(node){
            count++;
            node = node->next;
        }

        ListNode *l2 = head;
        for(int i = 0; i < count / 2; i++){
            l2 = l2->next;
        }

        if(count % 2 != 0){
            l2 = l2->next;
        }

        ListNode *prev = NULL;
        while(l2->next){
            ListNode *next = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = next;
        }
        l2->next = prev;

        while(l2){
            if(l2->val == head->val){
                l2 = l2->next;
                head = head->next;
            }else{
                return false;
            }
        }

        return true;
    }
};

TEST(leetcode_234_palindrome_linked_list, Basic)
{
    Solution *solution = new Solution();
    ListNode *head = list_init("1, 2, 1");
    EXPECT_TRUE(solution->isPalindrome(head));
    head = list_init("16557, 8725, 29125, 28873, 21702, 15483, 28441, 17845, 4317, 10914, 10914, 4317, 17845, 28441, 15483, 21702, 28873, 29125, 8725, 16557");
    EXPECT_TRUE(solution->isPalindrome(head));
    head = list_init("1, 4, 1, 1, 4, 1");
    EXPECT_TRUE(solution->isPalindrome(head));
    head = list_init("1, 0, 3, 4, 0, 1");
    EXPECT_FALSE(solution->isPalindrome(head));
    head = list_init("31900, 22571, 31634, 19735, 13748, 16612, 28299, 16628, 9614, 14444, 14444, 9614, 16628, 31900, 16612, 13748, 19735, 31634, 22571, 28299");
    EXPECT_FALSE(solution->isPalindrome(head));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
