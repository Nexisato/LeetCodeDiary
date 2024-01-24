/*
 * @Date: 2024-01-24 12:04:18
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2865-Beautiful-Towers-I/2865.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 单调栈 + DP
// 解法与 2866-Beautiful-Towers-II/2866.cpp 相同
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        const int n = maxHeights.size();
        vector<long long> f(n, 0), g(n, 0);
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && maxHeights[st.top()] > maxHeights[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            if (i && maxHeights[i] >= maxHeights[i - 1]) {
                f[i] = maxHeights[i] + f[i - 1];
            } else {
                int j = left[i];
                f[i] = 1LL * maxHeights[i] * (i - j) + ((j == -1) ? 0 : f[j]);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && maxHeights[i] >= maxHeights[i + 1]) {
                g[i] = maxHeights[i] + g[i + 1];
            } else {
                int j = right[i];
                g[i] = 1LL * maxHeights[i] * (j - i) + ((j == n) ? 0 : g[j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            res = max(res, f[i] + g[i] - maxHeights[i]);
        }


        return res;
    }
};
int main() {

    return 0;
}