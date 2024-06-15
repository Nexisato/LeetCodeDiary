/*
LeetCode 665: Non-Decreasing Array
@Description:
Given an array nums with n integers, your task is to check if it could
become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds
for every i (0-based) such that (0 <= i <= n - 2).

Constraints:
n == nums.length
1 <= n <= 10^4
-10^5 <= nums[i] <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. 要使得nums非递减，否则最多只能修改一个nums[i]使得其满足非递减，由此可推出：
    数组中至多有一个i满足nums[i]>nums[i + 1]
2. 若nums[i] > nums[i + 1]，要保证nums[i]不小于i之前的数，因此可以
    将nums[i]修改为nums[i + 1]，并检测数组是否已排好序
    将nums[i + 1]修改为nums[i]，并检测数组是否已排好序
*/
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() == 1)
			return true;
		for (int i = 0; i < nums.size() - 1; i++) {
			int x = nums[i], y = nums[i + 1];
			if (x > y) {
				nums[i] = y;
				if (is_sorted(nums.begin(), nums.end()))
					return true;
				nums[i] = x;
				nums[i + 1] = x;
				return is_sorted(nums.begin(), nums.end());
			}
		}
		return true;
	}
};
int main() { return 0; }