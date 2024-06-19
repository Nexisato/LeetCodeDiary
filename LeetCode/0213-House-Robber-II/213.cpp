/*
LeetCode 213: House Robeer II
@Description:
You are a professional robber planning to rob houses along a street. Each house has
a certain amount of money stashed. All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses
have a security system connected, and it will automatically contact the police if two
adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return
the maximum amount of money you can rob tonight without alerting the police.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：动态规划
基本思路同 House Robber I，但不同的是，第一间和最后一间房屋相邻，因此不能同一晚上偷窃
因此比较 0~n-2 和 1~n-1 区间的最大值
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		else if (n == 2)
			return max(nums[0], nums[1]);
		int res1 = 0, res2 = 0;
		int pre = 0, cur = 0;
		for (int i = 0; i < n - 1; ++i) {
			res1 = max(cur, pre + nums[i]);
			pre = cur;
			cur = res1;
		}
		pre = 0;
		cur = 0;
		for (int i = 1; i < n; ++i) {
			res2 = max(cur, pre + nums[i]);
			pre = cur;
			cur = res2;
		}
		return max(res1, res2);
	}
};
int main() { return 0; }