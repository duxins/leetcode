//  225. Implement Stack using Queues
//  
//  Implement the following operations of a stack using queues.
//
//  push(x) -- Push element x onto stack.
//  pop() -- Removes the element on top of the stack.
//  top() -- Get the top element.
//  empty() -- Return whether the stack is empty.
//
//  Notes:
//      You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
//      Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
//      You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
//
//  Update (2015-06-11):
//      The class name of the Java function had been updated to MyStack instead of Stack.
//
//  Tags: Stack, Design
//  
//  https://leetcode.com/problems/implement-stack-using-queues/    

#include <iostream>
#include <gtest/gtest.h>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q;

public:
    // Push element x onto stack.
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

TEST(leetcode_225_implement_stack_using_queues, Basic)
{
    Stack *stack = new Stack();
    EXPECT_TRUE(stack->empty());
    stack->push(1);
    stack->push(2);
    EXPECT_EQ(2, stack->top());
    stack->pop();
    EXPECT_EQ(1, stack->top());
    stack->pop();
    EXPECT_TRUE(stack->empty());
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
