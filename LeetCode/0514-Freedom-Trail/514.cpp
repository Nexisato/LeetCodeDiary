/*
 * @Date: 2024-01-29 10:10:12
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0514-Freedom-Trail/514.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// DP
class Solution {
public:
	int findRotateSteps(string ring, string key) {
		const int n = ring.size();
		const int m = key.size();
		unordered_map<char, vector<int>> pos;
		for (int i = 0; i < n; ++i) {
			char a = ring[i];
			pos[a].push_back(i);
		}
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		for (auto& idx : pos[key[0]])
			dp[0][idx] = min(idx, n - idx) + 1;
		// dp[i][j] 表示拼写出 key 的第 i 个字符，ring 的第 j 个字符与 12:00 方向对齐的最少步数
		// dp[i][j] = min dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1
		for (int i = 1; i < m; ++i) {
			char cur = key[i];
			char last = key[i - 1];
			for (auto& j : pos[cur]) {
				for (auto& k : pos[last]) {
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
				}
			}
		}
		int res = *min_element(dp[m - 1].begin(), dp[m - 1].end());
		return res;
	}
};
int main() { return 0; }