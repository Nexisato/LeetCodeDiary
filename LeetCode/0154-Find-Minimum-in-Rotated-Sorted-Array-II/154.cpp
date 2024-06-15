/*
LeetCode 154: Find Minimum in Rotated Sorted Array II
@Description:

Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

Constraints:
n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.
 
Follow up: This is the same as Find Minimum in Rotated Sorted Array but with duplicates.
Would allow duplicates affect the run-time complexity? How and why?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分分区间讨论，这些有点麻烦，我选择遍历
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		int low = 0, high = nums.size() - 1;
		int mid = low + (high - low) / 2;
		while (low < high) {
			mid = low + (high - low) / 2;
			// mid在最小值右侧
			if (nums[mid] < nums[high])
				high = mid;
			// mid在最小值左侧
			else if (nums[mid] > nums[high])
				low = mid + 1;
			else
				//由于nums[mid]的存在，忽略右端点
				high -= 1;
		}
		return nums[low];
	}
};
int main() { return 0; }