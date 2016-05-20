//  232. Implement Queue using Stacks
//  
//  Implement the following operations of a queue using stacks.
//      push(x) -- Push element x to the back of queue.
//      pop() -- Removes the element from in front of queue.
//      peek() -- Get the front element.
//      empty() -- Return whether the queue is empty.

//  Notes:
//  You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size,
//  and is empty operations are valid.
//  Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or
//  deque (double-ended queue), as long as you use only standard operations of a stack.
//  You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
//
//  Tags: Stack, Design
//  
//  https://leetcode.com/problems/implement-queue-using-stacks/    

#include <iostream>
#include <gtest/gtest.h>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> s1, s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s1.pop();
    }

    // Get the front element.
    int peek(void) {
        return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};


TEST(leetcode_232_implement_queue_using_stacks, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->empty());

    solution->push(1);
    solution->push(2);
    solution->push(3);

    EXPECT_EQ(1, solution->peek());
    solution->pop();
    EXPECT_EQ(2, solution->peek());
    solution->pop();
    EXPECT_EQ(3, solution->peek());
    EXPECT_FALSE(solution->empty());
    solution->pop();
    EXPECT_TRUE(solution->empty());
    solution->push(4);
    EXPECT_EQ(4, solution->peek());
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
