/*
LeetCode 81: Search in Rotated Sort Array
@Description:
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown
pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ...,
nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7]
might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums,
or false if it is not in nums.

Constraints:
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums is guaranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

Follow up: This problem is the same as Search in Rotated Sorted Array,
where nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分查找
*/
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int n = (int)nums.size();
		if (!n)
			return -1;
		if (n == 1)
			return nums[0] == target ? 0 : -1;
		int low = 0, high = n - 1, mid = (low + high) / 2;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			/*分区间讨论*/
			//[0,mid]有序
			if (nums[0] <= nums[mid]) {
				if (nums[0] <= target && target < nums[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			//[0, mid]无序
			else {
				if (nums[mid] < target && target <= nums[n - 1])
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
		return -1;
	}
};
int main() { return 0; }