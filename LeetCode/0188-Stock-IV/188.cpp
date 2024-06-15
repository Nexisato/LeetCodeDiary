/*
 * @Date: 2024-01-17 14:15:19
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0188_Stock_IV/188.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	// 有了前几次的经验，这次可以直接按照 2k 初始化
	int maxProfit(int k, vector<int>& prices) {
		const int n = prices.size();
		if (n <= 1)
			return 0;
		// 0-无票，odd-买入，even-卖出
		vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
		for (int i = 0; i < k; ++i) {
			int idx = 2 * i + 1;
			dp[0][idx] = -prices[0];
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				int odd = 2 * j + 1; // 买入
				int even = odd + 1;  // 卖出
				dp[i][odd] = max(dp[i - 1][odd], dp[i - 1][odd - 1] - prices[i]);
				dp[i][even] = max(dp[i - 1][even], dp[i - 1][odd] + prices[i]);
			}
		}
		return dp[n - 1][2 * k];
	}
};
int main() { return 0; }