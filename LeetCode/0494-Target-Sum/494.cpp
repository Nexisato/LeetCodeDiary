/*
LeetCode 494: Target Sum
@Description:
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before
each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the
expression "+2-1". Return the number of different expressions that you can build, which evaluates to target.

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：动态规划-背包问题
dp[i][j]表示为nums前i个元素和为j的方案数
dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]

*由于sum(nums[i])不超过1000，因此j的最小值为-1000，因此初始化需要加上1000
dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000]
dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000]
*/
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(2001, 0));
		dp[0][nums[0] + 1000] = 1;
		dp[0][-nums[0] + 1000] += 1;

		for (int i = 1; i < n; ++i)
			for (int sum = -1000; sum <= 1000; ++sum)
				if (dp[i - 1][sum + 1000] > 0) {
					dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
					dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
				}
		return dp[n - 1][target + 1000];
	}
};
int main() { return 0; }