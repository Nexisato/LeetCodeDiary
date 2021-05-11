/*
LeetCode 264: Ugly Number II
@Description:
Given an integer n, return the nth ugly number.

Ugly number is a positive number whose prime factors only include 2, 3, and/or 5.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：利用最小堆
1. 要得到从小到大第n个丑数，可以用最小堆实现
2. 取出堆顶元素x，则 2x、3x、5x也是丑数，应当入堆
3. 上述做法容易导致堆中出现重复元素，因此加入哈希集合去重
*/
class Solution {
private:
    using L = long;
public:
    int nthUglyNumber(int n) {
        if (n <= 6)
            return n;
        vector<int> multis = {2, 3, 5};
        priority_queue<L, vector<L>, greater<L>> minHeap;
        unordered_set<L> marked;
        marked.insert(1L);
        minHeap.push(1L);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            L elem = minHeap.top();
            res = (int)elem;
            minHeap.pop();
            for (const auto& multi : multis) {
                L tmp = elem * multi;
                if (!marked.count(tmp)) {
                    marked.insert(tmp);
                    minHeap.push(tmp);
                }
            }
        }
        return res;
    }
};
int main() {


    return 0;
}