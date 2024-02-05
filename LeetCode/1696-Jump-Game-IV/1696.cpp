/*
 * @Date: 2024-02-05 07:31:26
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/1696-Jump-Game-IV/1696.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 直接 DP 会超时
// 引入 堆 优化 
// 1. 用优先队列维护当前位置的最大值
// 2. 用一个变量记录当前位置的最大值
// 3. 如果当前位置的最大值小于等于当前位置的值，那么就更新当前位置的最大值
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        // dp 记录以当前位置结尾的最大值
        vector<int> dp(n, INT32_MIN);
        // 最大堆维护 i - k ~ i 的最大值
        priority_queue<pair<int, int>> pq;
        dp[0] = nums[0];
        pq.push({dp[0], 0});
        for (int i = 1; i < n; ++i) {
            while (!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }
            dp[i] = pq.top().first + nums[i];
            pq.push({dp[i], i});
        }
        return dp[n - 1];
    }
};
int main() {

    vector<int> nums = {1,-1,-2,4,-7,3};
    int k = 2;
    Solution solution;
    cout << solution.maxResult(nums, k) << endl;
    

    return 0;
}