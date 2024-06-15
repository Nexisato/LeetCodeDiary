/*
LeetCode 152: Maximum Product Subarray
@Description:
Given an integer array nums, find a contiguous non-empty subarray within the array that
has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Constraints:
1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：根据正负性进行划分
1. 维护两个dp数组，dp_min[i]和dp_max[i]，分别表示以nums[i]结尾的子数组乘积的最小值和最大值
2.  dp_max[i] = max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i])
    dp_min[i] = min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i])
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		vector<int> dpMin(nums), dpMax(nums);
		for (int i = 1; i < n; ++i) {
			int curMax = dpMax[i - 1] * nums[i], curMin = dpMin[i - 1] * nums[i];
			dpMax[i] = max(nums[i], max(curMax, curMin));
			dpMin[i] = min(nums[i], min(curMax, curMin));
		}
		return *max_element(dpMax.begin(), dpMax.end());
	}
};
int main() { return 0; }