/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0153-Find-Minimum-in-Rotated-Sorted-Array/153.cpp
 * @Description:
 */
/*
LeetCode 153: Find Minimum in Rotated Sorted Array
@Description:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the
array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of
this array.

Constraints:
n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：二分查找
// 思考一下旋转数组的特性
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		const int n = nums.size();
		int l = 0, r = n - 1;
		int res = INT_MAX;
		while (l < r) {
			int mid = l + (r - l) / 2;
			// 收缩右边界
			if (nums[mid] < nums[r]) {
				r = mid;
			} else {
				// 收缩左边界
				l = mid + 1;
			}
		}
		return nums[l];
	}
};
int main() { return 0; }