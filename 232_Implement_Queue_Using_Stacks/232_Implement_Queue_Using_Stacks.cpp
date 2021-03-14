/*
LeetCode 232: Implement Queue Using Stacks
@Description:
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top, 
peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. 
You may simulate a stack using a list or deque (double-ended queue) as long as 
you use only a stack's standard operations.
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? 
In other words, performing n operations will take overall O(n) time even if 
one of those operations may take longer.

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双栈模拟
一个栈用于入队，另一个栈用于调用pop()时出队
*/
class MyQueue {
private:
    vector<int> nums;
    vector<int> q;
    void remov() {
        while (!nums.empty()) {
            q.emplace_back(nums.back());
            nums.pop_back();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
        nums.clear();
        q.clear();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        nums.emplace_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if  (q.empty()) 
            remov();
        int res = q.back();
        q.pop_back();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (q.empty())
            remov();
        return q.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty() && nums.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {

    return 0;
}