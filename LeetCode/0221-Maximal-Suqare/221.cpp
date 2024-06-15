/*
 * @Date: 2024-01-18 15:31:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0221_Maximal_Suqare/221.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		const int m = matrix.size();
		const int n = matrix[0].size();
		if (m == 0 || n == 0)
			return 0;
		// DP 用来记录边长的最大值
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		int maxSide = 0;
		dp[1][1] = matrix[0][0] - '0';
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (matrix[i - 1][j - 1] == '1') {
					// 由于是正方形，所以只需要考虑左上，左，上三个位置
					// 取最小值 + 1
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					maxSide = max(maxSide, dp[i][j]);
				}
			}
		}
		return maxSide * maxSide;
	}
};
int main() { return 0; }