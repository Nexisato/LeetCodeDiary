/*
LeetCode 724: Find Pivot Index
@Description:
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of
the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are
no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Constraints:
1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：前缀和优化
*/
class Solution {
public:
	int pivotIndex_raw(vector<int>& nums) {
		int pivot = 0;
		int n = nums.size();
		int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0) - nums[0];
		while (pivot < n - 1) {
			if (leftSum == rightSum)
				return pivot;
			++pivot;
			leftSum += nums[pivot - 1];
			rightSum -= nums[pivot];
		}
		return (leftSum == rightSum) ? (pivot) : -1;
	}
	// SumLeft = totalSum - nums[i] - SumRight, SumLeft = SumRight ==> 2 * Sum + nums[i]
	// = totalSum
	int pivotIndex_opt(vector<int>& nums) {
		int n = nums.size();
		int totalSum = accumulate(nums.begin(), nums.end(), 0);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (2 * sum + nums[i] == totalSum)
				return i;
			sum += nums[i];
		}
		return -1;
	}
};
int main() { return 0; }