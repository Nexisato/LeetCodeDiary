/*
LeetCode 523: Continuous Subarray Sum
@Description:
Given an integer array nums and an integer k, return true if nums has a continuous
subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k.
0 is always a multiple of k.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
0 <= sum(nums[i]) <= 2^31 - 1
1 <= k <= 2^31 - 1
*/
#include <iostream>
#include <unordered_map>
#include <vector>
/*
思路：前缀和+哈希
*/
class Solution {
public:
	bool checkSubarraySum(std::vector<int>& nums, int k) {
		int n = nums.size();
		std::unordered_map<int, int> table;
		table[0] = -1;
		int preSum = 0;
		for (int i = 0; i < n; ++i) {
			preSum = (preSum + nums[i]) % k;
			if (table.count(preSum)) {
				if (i - table[preSum] >= 2)
					return true;
			} else
				table[preSum] = i;
		}
		return false;
	}
};

int main() { return 0; }