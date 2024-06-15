/*
LeetCode 368: Largest Divisible Subset
@Description:
Given a set of distinct positive integers nums, return the largest subset answer
such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
- answer[i] % answer[j] == 0, or
- answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：序列DP + 最长上升子序列
题意为：所给定的符号整除子集中的任意两个值，必然满足[较大值]是[较小值]的倍数
直接模拟的方法是不行的，可以保证能够得到[可行解]，但并不能保证可以得到[最优解]
定义dp[i]为前i个数字以nums[i]为结尾的最长[整除子集]的长度
对于dp[i]：
    - 若在i之前找不到符合条件的nums[i]%nums[j] == 0，则 dp[i] = 1，nums[i]作为独立整除子集
    - 若在i之前能够找到符合条件的位置j，则选择符合条件的dp[j]最大值，dp[i] = dp[j] + 1
同时，为了方便记录方案item，需要额外开一个数组g[]记录状态i从哪个状态转移过来
*/
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> dp(n, 0), g(n, 0);
		for (int i = 0; i < n; ++i) {
			int len = 1, prevState = i;
			for (int j = 0; j < i; ++j)
				if (nums[i] % nums[j] == 0)
					if (dp[j] + 1 > len) {
						len = dp[j] + 1;
						prevState = j;
					}
			dp[i] = len;
			g[i] = prevState;
		}
		// To get the index of the max element from dp[n]
		int idx = max_element(dp.begin(), dp.end()) - dp.begin();
		int maxL = dp[idx];
		vector<int> res;
		for (int i = 0; i < maxL; ++i) {
			res.emplace_back(nums[idx]);
			idx = g[idx];
		}
		return res;
	}
};
int main() { return 0; }