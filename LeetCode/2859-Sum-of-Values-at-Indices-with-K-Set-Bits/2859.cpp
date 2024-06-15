/*
 * @Date: 2024-01-25 08:56:58
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2859-Sum-of-Values-at-Indices-with-K-Set-Bits/2859.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int sumIndicesWithKSetBits(vector<int>& nums, int k) {
		const int n = nums.size();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			int cur = i;
			while (cur) {
				cnt += (cur & 1);
				cur >>= 1;
			}

			if (cnt == k) {
				res += nums[i];
			}
		}
		return res;
	}
};
int main() {
	Solution sol;
	vector<int> nums = {5, 10, 1, 5, 2};
	int k = 1;
	cout << sol.sumIndicesWithKSetBits(nums, k) << endl;
	return 0;
}