/*
 * @Date: 2024-01-12 11:33:03
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0064_Minimum_Path_Sum/64.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		dp[1][1] = grid[0][0];
		// 初始化这里一定要设置好
		for (int i = 1; i <= m; ++i)
			dp[i][1] = grid[i - 1][0] + dp[i - 1][1];
		for (int j = 1; j <= n; ++j)
			dp[1][j] = grid[0][j - 1] + dp[1][j - 1];

		for (int i = 2; i <= m; ++i)
			for (int j = 2; j <= n; ++j) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1]; // 注意这里的grid下标
			}

		return dp[m][n];
	}
};

int main() { return 0; }