//  141. Linked List Cycle
//  
//  Given a linked list, determine if it has a cycle in it.
//  Follow up:
//  Can you solve it without using extra space?
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List, Two Pointers
//  
//  https://leetcode.com/problems/linked-list-cycle/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(slow && fast && fast->next){
            if(slow == fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

TEST(leetcode_141_linked_list_cycle, Basic)
{
    Solution *solution = new Solution();
    ListNode *head = list_init({0, 1, 2, 3, 4, 5});
    EXPECT_FALSE(solution->hasCycle(head));

    head = list_init({0});
    EXPECT_FALSE(solution->hasCycle(head));

    head = list_init({0, 1, 2});
    EXPECT_FALSE(solution->hasCycle(head));

    head = list_init({});
    EXPECT_FALSE(solution->hasCycle(head));

    head = list_init({0});
    head->next = head;
    EXPECT_TRUE(solution->hasCycle(head));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
