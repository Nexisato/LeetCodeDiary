/*
LeetCode 225: Implementing Stack Using Queues
@Description:
Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all 
the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:
- void push(int x) Pushes element x to the top of the stack.
- int pop() Removes the element on the top of the stack and returns it.
- int top() Returns the element on the top of the stack.
- boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and 
is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list 
or deque (double-ended queue), as long as you use only a queue's standard operations.

Follow-up: Can you implement the stack such that each operation is amortized O(1) time complexity? 
In other words, performing n operations will take overall O(n) time even if one of those operations may take longer. 
You can use more than two queues.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class MyStack {
private:
    queue<int> nums;
public:
    /** Initialize your data structure here. */
    MyStack() {
        this->nums = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        nums.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        int elem = nums.back();
        while (!nums.empty()) {
            int num = nums.front();
            nums.pop();
            if (num != elem)
                tmp.push(num);
            else
                break;
        }
        while (!tmp.empty()) {
            nums.push(tmp.front());
            tmp.pop();
        }
        return elem;
    }
    
    /** Get the top element. */
    int top() {
        return nums.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return nums.empty();
    }
};

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        this->q1 = queue<int>();
        this->q2 = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int elem = q1.front();
        q1.pop();
        return elem;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {

    return 0;
}