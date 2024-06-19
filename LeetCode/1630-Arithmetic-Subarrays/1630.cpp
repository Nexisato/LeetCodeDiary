#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 直接模拟即可
 *
 */
class Solution {
public:
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
	                                      vector<int>& r) {
		int n = nums.size(), m = l.size();
		vector<bool> isArithmetic(m, true);
		for (int i = 0; i < m; ++i) {
			int left = l[i], right = r[i];
			vector<int> tmp(nums.begin() + left, nums.begin() + right + 1);
			sort(tmp.begin(), tmp.end());
			int delta = tmp[1] - tmp[0];
			for (int j = 1; j < tmp.size(); ++j)
				if (tmp[j] - tmp[j - 1] != delta) {
					isArithmetic[i] = false;
					break;
				}
		}
		return isArithmetic;
	}
};
int main() { return 0; }