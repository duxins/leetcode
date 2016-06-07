//  155. Min Stack
//  
//  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//  push(x) -- Push element x onto stack.
//  pop() -- Removes the element on top of the stack.
//  top() -- Get the top element.
//  getMin() -- Retrieve the minimum element in the stack.
//  Example:
//  MinStack minStack = new MinStack();
//  minStack.push(-2);
//  minStack.push(0);
//  minStack.push(-3);
//  minStack.getMin();   --> Returns -3.
//  minStack.pop();
//  minStack.top();      --> Returns 0.
//  minStack.getMin();   --> Returns -2.
//
//  Tags: Stack, Design
//  
//  https://leetcode.com/problems/min-stack/    

#include <iostream>
#include <gtest/gtest.h>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minStack;

public:

    void push(int x) {
        st.push(x);

        if(minStack.empty() || minStack.top() >= x){
            minStack.push(x);
        }
    }

    void pop() {
        int n = st.top();
        st.pop();
        if(n == minStack.top()){
             minStack.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

TEST(leetcode_155_min_stack, Basic)
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    EXPECT_EQ(-3, minStack->getMin());
    minStack->pop();
    EXPECT_EQ(0, minStack->top());
    EXPECT_EQ(-2, minStack->getMin());
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
