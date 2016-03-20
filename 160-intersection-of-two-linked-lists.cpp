//  160. Intersection of Two Linked Lists
//  
//  Write a program to find the node at which the intersection of two singly linked lists begins.
//  For example, the following two linked lists:
//
//  A:          a1 → a2
//                      ↘
//                        c1 → c2 → c3
//                      ↗
//  B:      b1 → b2 → b3
//
//  begin to intersect at node c1.
//
//  Notes:
//
//      If the two linked lists have no intersection at all, return null.
//      The linked lists must retain their original structure after the function returns.
//      You may assume there are no cycles anywhere in the entire linked structure.
//      Your code should preferably run in O(n) time and use only O(1) memory.
//      Credits:Special thanks to @stellari for adding this problem and creating all test cases.
//      Subscribe to see which companies asked this question
//  
//  Tags: Linked List
//  
//  https://leetcode.com/problems/intersection-of-two-linked-lists/    

#include <iostream>
#include <gtest/gtest.h>
#include <list/list.h>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        int len1 = getListLength(headA);
        int len2 = getListLength(headB);

        int diff = abs(len1 - len2);

        if(len1 > len2){
            while(diff--) headA = headA->next;
        }else{
            while(diff--) headB = headB->next;
        }

        while(headA){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }

private:

    int getListLength(ListNode *node){
        int len = 0;
        while(node){
            node = node->next;
            len++;
        }
        return len;
    }
};

TEST(leetcode_160_intersection_of_two_linked_lists, Basic)
{
//  1:          1 →  1
//                      ↘
//  3:                   3 → 3
//                      ↗
//  2:      2 →  2  →  2
//
//  4:      4 →  4  →  4 → 4

    Solution *solution = new Solution();
    int num1[] = {1, 1};
    int num2[] = {2, 2, 2};
    int num3[] = {3, 3};
    int num4[] = {4, 4, 4, 4};
    ListNode *list1 = list_init(num1, 1);
    ListNode *list2 = list_init(num2, 3);
    ListNode *list3 = list_init(num3, 2);
    ListNode *list4 = list_init(num4, 4);
    list_add_tail(list1, list3);
    list_add_tail(list2, list3);

    EXPECT_EQ(list3, solution->getIntersectionNode(list1, list2));
    EXPECT_EQ(NULL, solution->getIntersectionNode(list1, list4));
    EXPECT_EQ(NULL, solution->getIntersectionNode(list3, list4));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
