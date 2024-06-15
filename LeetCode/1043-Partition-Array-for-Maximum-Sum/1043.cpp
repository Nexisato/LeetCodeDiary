#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * DP 求解，dp[i] 作为 arr[0]~arr[i-1] 分为 k 份的分割和。
 * 新加入 arr[i]，包含 arr[i] 在内的 j (j=1~k) 长度的子数组，得到的和为 dp[i] = dp[i - j] + max(arr[i - 1], arr[i - 2],
 * ..., arr[i - j]) * j
 */
class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		const int n = arr.size();
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				if (i - j < 0)
					break;
				int maxVal = *max_element(arr.begin() + (i - j), arr.begin() + i);
				int curSum = dp[i - j] + maxVal * j;
				dp[i] = max(dp[i], curSum);
			}
		}
		return dp[n];
	}
};
int main() { return 0; }