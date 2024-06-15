/*
 * @Date: 2024-01-17 12:35:00
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0123_Stock_III/123.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		if (n <= 1)
			return 0;
		// 无票，第一次买入，第一次卖出，第二次买入，第二次卖出
		vector<vector<int>> dp(n, vector<int>(5, 0));
		dp[0][1] = -prices[0];
		dp[0][3] = -prices[0]; // 第二次买入，初始化也是先减去
		for (int i = 1; i < n; ++i) {
			dp[i][1] = max(dp[i - 1][1], -prices[i]);
			// 第一次卖出
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
			// 第二次买入
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
			// 第二次卖出
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
		}
		return dp[n - 1][4];
	}
};

int main() { return 0; }