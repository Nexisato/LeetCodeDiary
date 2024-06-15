#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 固定一个锚点，左右两侧分别记录两个滑动窗口
 */
class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		int n = nums.size();
		vector<int> prefixSum(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			prefixSum[i + 1] = prefixSum[i] + nums[i];
		}
		int res = -1;
		// 包含 firstLen 和 secondLen 分别在左右两边的情况
		for (int i = firstLen, t = 0; i + secondLen - 1 < n; ++i) {
			t = max(t, prefixSum[i] - prefixSum[i - firstLen]);          //左边不包含 nums[i]
			res = max(res, t + prefixSum[i + secondLen] - prefixSum[i]); //右边包含 nums[i]
		}

		for (int i = secondLen, t = 0; i + firstLen - 1 < n; ++i) {
			t = max(t, prefixSum[i] - prefixSum[i - secondLen]);
			res = max(res, t + prefixSum[firstLen + i] - prefixSum[i]);
		}
		return res;
	}
};
int main() { return 0; }