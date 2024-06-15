#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 固定一个点进行双指针遍历即可
 *
 */
class Solution {
public:
	int arithmeticTriplets(vector<int>& nums, int diff) {
		int res = 0;
		int n = nums.size();
		for (int i = 1; i < n - 1; ++i) {
			int l = 0, r = n - 1;
			while (l < i && i < r) {
				int diff1 = nums[i] - nums[l];
				int diff2 = nums[r] - nums[i];
				if (diff1 == diff2 && diff1 == diff) {
					++res;
					++l;
					--r;
				} else if (diff1 > diff2)
					++l;
				else
					--r;
			}
		}

		return res;
	}
};
int main() {
	vector<int> nums({4, 5, 6, 7, 8, 9});
	int res = 0;

	return 0;
}