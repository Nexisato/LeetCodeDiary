/*
LeetCode 346: Moving Average from Data Stream
@Description:
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:
- MovingAverage(int size) Initializes the object with the size of the window size.
- double next(int val) Returns the moving average of the last size values of the stream.

Constraints:
1 <= size <= 1000
-10^5 <= val <= 10^5
At most 104 calls will be made to next.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：利用队列维护滑动窗口
*/
class MovingAverage {
private:
    queue<int> q;
    int cap;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        while (!q.empty())
            q.pop();
        this->cap = size;
        this->sum = 0;
    }
    
    double next(int val) {
        if (q.size() < cap) {
            q.push(val);
            sum += val;
            return (double)sum / q.size();
        }
        sum -= q.front();
        q.pop();
        q.push(val);
        sum += val;
        return (double)sum / cap;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
int main() {
    int size = 3;
    MovingAverage* obj = new MovingAverage(size);
    double param_1 = obj->next(1);
    double param_2 = obj->next(10);
    double param_3 = obj->next(3);
    double param_4 = obj->next(5);

    return 0;
}