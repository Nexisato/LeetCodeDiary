/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0155-MinStack/155-MinStack.cpp
 * @Description:
 */
/*
LeetCode: 155 MinStack
Description:
Design a stack that supports push, pop, top, and retrieving the minimum element in
constant time. -push(x) -- Push element x onto stack. -pop() -- Removes the element on
top of the stack. -top() -- Get the top element. -getMin() -- Retrieve the minimum
element in the stack.

Constraints:
Methods pop, top and getMin operations will always be called on non-empty stacks.
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
思路：
1. 维护一个[数据栈]和一个[辅助栈]
2. 数据栈用于存放每个新入栈的x，辅助栈用于存放每个x入栈时，数据栈中已有元素的最小值
*/
class MinStack {
	stack<int> data;
	stack<int> min_stack;

public:
	/** initialize your data structure here. */
	MinStack() { min_stack.push(INT32_MAX); }

	void push(int x) {
		data.push(x);
		if (min_stack.empty() || x <= min_stack.top())
			min_stack.push(x);
		if (x > min_stack.top())
			min_stack.push(min_stack.top());
		// min_stack.push(min(min_stack.top(),x));
	}

	void pop() {
		data.pop();
		min_stack.pop();
	}

	int top() { return data.top(); }

	int getMin() { return min_stack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() { return 0; }