/*
 * @Date: 2024-01-19 23:27:46
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2809-Minimum-Time-to-Make-Array-Sum-at-Most-K/2809.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// 考虑一下减少量
// nums1[i] 第 k 秒置零，在第 t 秒时为 nums2[i] * (t - k)
// 减少量为 nums1[i] + nums2[i] * k
// 根据排序不等式，对 nums2[i]小的值，越早置零越好
class Solution {
public:
	int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
		const int n = nums1.size();
		int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
		int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

		vector<int> idx(n, 0);
		iota(idx.begin(), idx.end(), 0); // 生成 0 ~ n-1 的序列
		// 按照 nums2[i] 从小到大排序，记录下标
		sort(idx.begin(), idx.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });
		// 核心在于排序不等式，nums1[i] + nums2[i] * k , 为第 k 个下标的数对减小量的最大贡献

		// 下面的 dp 为 0-1 背包问题的降维版
		// dp[i] 表示前 i 个数中，减小值能得到的最大值
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			int num1_order = nums1[idx[i]];
			int num2_order = nums2[idx[i]];
			for (int j = i + 1; j; --j) {
				int curVal = num1_order + num2_order * j;
				dp[j] = max(dp[j], dp[j - 1] + curVal);
			}
		}
		for (int t = 0; t <= n; t++) {
			if (sum1 + sum2 * t - dp[t] <= x) {
				return t;
			}
		}
		return -1;
	}
};
int main() { return 0; }