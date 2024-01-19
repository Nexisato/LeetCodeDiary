/*
 * @Date: 2024-01-08 11:48:59
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0373_Find_K_Pairs_With_Smallest_Sums/373.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// CORE: 
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        const int m = nums1.size(), n = nums2.size();
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        // cmp 为初始化pq的比较函数，这里是最小堆，所以是大于号
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        // 先把 0-indexed 的最小的 k 个数放进去
        for (int i = 0; i < min(m, k); ++i) {
            pq.emplace(i, 0);
        }
        while (k-- > 0 && !pq.empty()) {
            auto [idx1, idx2] = pq.top();
            pq.pop();
            res.push_back({nums1[idx1], nums2[idx2]});
            // 假设前 n 个小的数对的索引为 (a1, b1), (a2, b2)....(an, bn)
            // 这里很巧妙的一点是：第 n+1 个小的数在 (a1 + 1, b1), (a1, b1 + 1), (a2 + 1, b2), (a2, b2 + 1).. 中
            if (idx2 + 1 < n) {
                pq.emplace(idx1, idx2 + 1);
            }

        }
        return res;
    }
};
int main() {

    return 0;
}