#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/**
 * 思路：
 * 单调栈（非递增） + 优先队列
 *
 */
class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        const int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        // 优先队列，存储的是 值 和 下标
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; 

        for (int i = 0; i < n; ++i) {
            // 到这里，栈顶元素的下一个更大元素
            while (!pq.empty() && pq.top().first < nums[i]) {
                res[pq.top().second] = nums[i];
                pq.pop();
            }

            // 非单调递增栈，栈顶元素的下一个更大元素
            // 实际上这里记录的是第一个比 st.top() 大的元素
            while (!st.empty() && nums[i] > nums[st.top()]) {
                pq.push({nums[st.top()] , st.top()});
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    Solution ss;
    vector<int> nums = {2, 4, 0, 9, 6};
    vector<int> res = ss.secondGreaterElement(nums);
    for (auto &i : res) {
        cout << i << " ";
    }
    return 0;
}