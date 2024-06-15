#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * 思路：
 * 单调栈 + DP，确实稍微有点难了
 * 定义
 * f[i] 为前 i 座塔中，以第 i 座塔为最高塔时，所得的高度和
 * g[i] 为 i 座塔及以后，以第 i 座塔为最高塔时，所得的高度和的最大值
 * 所得到的答案为 max(f[i] + g[i] - maxHeights[i])
 *
 * 单调栈的思路：
 * left[] 数组，记录每个位置左边第一个比它小或等的位置
 * right[] 数组，记录每个位置右边第一个比它小或等的位置
 */
class Solution {
public:
	long long maximumSumOfHeights(vector<int>& maxHeights) {
		const int n = maxHeights.size();
		long long res = 0;
		stack<int> st;
		vector<int> left(n, -1), right(n, n);
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
				st.pop();
			}
			if (!st.empty())
				left[i] = st.top();
			st.push(i);
		}
		st = stack<int>();
		for (int i = n - 1; ~i; --i) {
			while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
				st.pop();
			}
			if (!st.empty())
				right[i] = st.top();
			st.push(i);
		}
		vector<long long> f(n, 0), g(n, 0);
		for (int i = 0; i < n; ++i) {
			if (i && maxHeights[i] >= maxHeights[i - 1]) {
				f[i] = maxHeights[i] + f[i - 1];
			} else {
				int j = left[i];
				f[i] = 1LL * maxHeights[i] * (i - j) + ((j == -1) ? 0 : f[j]);
			}
		}

		for (int i = n - 1; ~i; --i) {
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

int main() { return 0; }