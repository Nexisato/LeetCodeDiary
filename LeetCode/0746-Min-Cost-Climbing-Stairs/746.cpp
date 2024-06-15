/*
LeetCode 746: Min Cost Climbing Stairs
@Description:
You are given an integer array cost where cost[i] is the cost of ith step on a
staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Constraints:
2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：动态规划
间隔1-2位，取较小值累加
*/
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		// int n = cost.size();
		// vector<int> dp(n + 1, 0);
		// dp[0] = dp[1] = 0;
		// for (int i = 2; i <= n; ++i)
		//     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		// return dp[n];
		const int n = cost.size();
		vector<int> dp(n, 0); // dp[i] 表示到达第 i 级台阶顶部的最小花费
		dp[0] = cost[0];
		dp[1] = cost[1];
		for (int i = 2; i < n; ++i) {
			dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
		}
		return min(dp[n - 1], dp[n - 2]);
	}
};
int main() { return 0; }