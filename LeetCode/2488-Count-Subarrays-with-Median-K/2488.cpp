#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 *
 *
 */
class Solution {
public:
	// int countSubarrays_O(n^2)(vector<int>& nums, int k) {
	//     int res = 0, kIdx = -1;
	//     const int n = nums.size();
	//     for (int i = 0; i < n; ++i) {
	//         if (nums[i] > k) nums[i] = 1;
	//         else if (nums[i] < k) nums[i] = -1;
	//         else {
	//             nums[i] = 0;
	//             kIdx = i;
	//         }
	//     }
	//     vector<int> prefix(n + 1, 0);
	//     for (int i = 1; i <= n; ++i)
	//         prefix[i] = prefix[i - 1] + nums[i - 1]; // sum(i, j) prefix[j + 1] - prefix[i]

	//     for (int r = kIdx; r < n; ++r)
	//         for (int l = kIdx; l >= 0; --l) {
	//             int curSum = prefix[r + 1] - prefix[l];
	//             res += (curSum == 0 || curSum == 1) ? 1 : 0;
	//         }

	//     return res;
	// }
	int countSubarrays(vector<int>& nums, int k) {
		const int n = nums.size();
		int res = 1, kIdx = find(nums.begin(), nums.end(), k) - nums.begin();
		int cnt[n << 1 | 1]; // 开一个 2n + 1 大的数组，用于记录当前数组中，右侧比k大与比k小的元素个数的差值
		memset(cnt, 0, sizeof(cnt));
		int x = 0;
		for (int i = kIdx + 1; i < n; ++i) {
			x += (nums[i] > k) ? 1 : -1;
			if (x == 0 || x == 1)
				++res;
			++cnt[x + n];
		}
		x = 0;
		for (int i = kIdx - 1; i >= 0; --i) {
			x += (nums[i] > k) ? 1 : -1;
			if (x == 0 || x == 1)
				++res;
			res += cnt[-x + n] + cnt[-x + n + 1];
		}

		return res;
	}
};
int main() {
	Solution ss;
	vector<int> nums({3, 2, 1, 4, 5});
	int res = ss.countSubarrays(nums, 4);

	cout << res << endl;

	return 0;
}