/*
 * @Date: 2024-02-03 07:50:29
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/1690-Stone-Game-VII/1690.cpp
 * @Description:
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// A: 最大化 Difference
// B: 最小化 Difference
// 用 DP 表示得分差, 谁先手，谁得分最大
// ===================================================
// sum(stones[i + 1], stones[j]) - dp[i + 1][j])
//      = 鲍勃当前操作得分 - （爱丽丝的总分 - 鲍勃的总分）
//      = 鲍勃当前操作得分 + 鲍勃的总分 - 爱丽丝的总分
//      = 鲍勃新的总分 - 爱丽丝的总分 > 0（谁先手谁最大）

class Solution {
public:
	int stoneGameVII(vector<int>& stones) {
		const int n = stones.size();
		vector<int> sum(n + 1, 0);
		// sum[j] - sum[i] 表示 stones[i] 到 stones[j - 1] 的石头总和
		for (int i = 0; i < n; ++i) {
			sum[i + 1] = sum[i] + stones[i];
		}
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 2; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				// sum[j + 1] - sum[i + 1] 表示 stones[i+1] 到 stones[j]
				// 的石头总和，移去 i sum[j] - sum[i] 表示 stones[i] 到 stones[j - 1]
				// 的石头总和，移去 j
				dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j],
				               sum[j] - sum[i] - dp[i][j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};
int main() {
	vector<int> stones({5, 3, 1, 4, 2});
	Solution* ss;
	int res = ss->stoneGameVII(stones);

	cout << res << endl;
	return 0;
}