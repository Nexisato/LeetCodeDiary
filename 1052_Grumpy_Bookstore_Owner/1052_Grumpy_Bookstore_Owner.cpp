/*
LeetCode 1052: Grumpy Bookstore Owner
@Description:
Today, the bookstore owner has a store open for customers.length minutes.  
Every minute, some number of customers (customers[i]) enter the store, 
and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  
If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  
When the bookstore owner is grumpy, the customers of that minute are not satisfied, 
otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, 
but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

Note:
1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. 遍历两次，一次计算grumpy[i] == 0的顾客数，一次计算镇定状态的顾客数(grumpy[i] == 1)
2. 遍历grumpy数组，将 grumpy[i] = 0的顾客数累加
3. 维护长度为X的滑动窗口，若对应grumpy[i] == 1，则累加，求得大小为X的窗口的最大累加值
4. 两次遍历结果相加即可
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0)
                res += customers[i];
        }
        int left = 0, right = 0;
        int tmpSum = 0, maxSum = 0;
        while (right < customers.size()) {
            tmpSum += (grumpy[right] == 1) ? customers[right] : 0;
            if (++right < X) continue;
            maxSum = max(maxSum, tmpSum);
            if (grumpy[left] == 1)
                tmpSum -= customers[left];
            ++left;
        }
        return res + maxSum;
    }
};
int main() {
    Solution ss;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    int res = ss.maxSatisfied(customers, grumpy, X);
    return 0;
}