//  142. Linked List Cycle II
//  
//  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//  Note: Do not modify the linked list.
//  Follow up:
//  Can you solve it without using extra space?
//
//  Tags: Linked List, Two Pointers
//  
//  https://leetcode.com/problems/linked-list-cycle-ii/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

TEST(leetcode_142_linked_list_cycle_ii, Basic)
{
    Solution *solution = new Solution();
    ListNode *head = list_init("1, 2, 3, 4");
    list_add_tail(head, head);
    EXPECT_EQ(head, solution->detectCycle(head));
}

TEST(leetcode_142_linked_list_cycle_ii, Basic1)
{
    // 1 -> 2 -> 3 -> 4 -> 1 -> 2 -> 3 -> 4
    //                     ^              |
    //                     |              |
    //                     |______________|

    Solution *solution = new Solution();
    ListNode *list1 = list_init("1, 2, 3, 4");
    ListNode *list2 = list_init("1, 2, 3, 4");
    list_add_tail(list2, list2);
    list_add_tail(list1, list2);
    EXPECT_EQ(list2, solution->detectCycle(list1));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
