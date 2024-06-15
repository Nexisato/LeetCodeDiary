/*
LeetCode: 198 House Robber
Description:
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them
is that adjacent houses have security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 400
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 假设dp[k]为前k个房子中偷到的最大金额（1<=k<=N）
2. k=0时，dp[k] = 0；k=1时，dp[k] = nums[0]
3. dp[k]分解为 k-1 和 k-2 两种情况
    - k-1 时，第k个房子不偷，dp[k]=dp[k-1]
    - k-2 时，第k-1个房子不偷，偷第k个房子和dp[k-2]，则 dp[k] = nums[k-1] + dp[k-2]
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		int N = nums.size();
		vector<int> dp(N + 1, 0);
		dp[0] = 0;
		dp[1] = nums[0];
		for (int i = 2; i <= N; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return dp[N];
	}
	int rob_spaceOpt(vector<int>& nums) {
		int cur = 0, pre = 0;
		int res = cur;
		for (int num : nums) {
			res = max(cur, pre + num);
			pre = cur;
			cur = res;
		}
		return res;
	}
};
int main() { return 0; }