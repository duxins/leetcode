//  24. Swap Nodes in Pairs
//  
//  Given a linked list, swap every two adjacent nodes and return its head.
//  For example,
//  Given 1->2->3->4, you should return the list as 2->1->4->3.
//  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
//  Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/swap-nodes-in-pairs/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *n = head->next;
        head->next = swapPairs(n->next);
        n->next = head;
        return n;
    }
};

void judge(vector<int> input, vector<int> expected){
    Solution solution = Solution();
    ListNode *head = list_init(input);
    EXPECT_EQ(expected, list_to_vector(solution.swapPairs(head)));
}

TEST(leetcode_024_swap_nodes_in_pairs, Basic)
{
    judge({1, 2, 3, 4}, {2, 1, 4, 3});
    judge({1, 2, 3, 4, 5, 6}, {2, 1, 4, 3, 6, 5 });
    judge({1, 2}, {2, 1});
    judge({1}, {1});
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
