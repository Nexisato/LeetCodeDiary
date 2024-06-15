/*
 * @Date: 2024-01-11 11:56:37
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0120_Triangle/120.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 正常的多维 DP
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		const int level = triangle.size();
		const int width = triangle[level - 1].size();
		vector<vector<int>> dp(level, vector<int>(width, INT32_MAX));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < level; ++i) {
			int length = triangle[i].size();
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			for (int j = 1; j < length; ++j) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
		int res = INT32_MAX;
		for (int i = 0; i < triangle[level - 1].size(); ++i)
			res = min(res, dp[level - 1][i]);
		return res;
	}
};
int main() { return 0; }