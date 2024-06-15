/*
 * @Date: 2024-01-21 20:38:57
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0410-Split-Array-Largest-Sum/410.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int splitArray(vector<int>& nums, int k) {
		const int n = nums.size();
		// dp[i][j]表示前i个数分成j组的最大连续子数组和的最小值
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT32_MAX));
		// sub[i]表示前i个数的和
		vector<int> sub(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			sub[i] = sub[i - 1] + nums[i - 1];
		}
		// 初始化
		for (int i = 1; i <= n; ++i) {
			dp[i][1] = sub[i];
		}
		for (int i = 1; i <= k; ++i) {
			dp[1][i] = nums[0];
		}
		// 状态转移
		for (int i = 2; i <= n; ++i) {
			for (int j = 2; j <= k; ++j) {
				int min_val = INT_MAX;
				for (int l = 1; l < i; ++l) {
					min_val = min(min_val, max(dp[l][j - 1], sub[i] - sub[l]));
				}
				dp[i][j] = min_val;
			}
		}

		return dp[n][k];
	}
};
int main() { return 0; }